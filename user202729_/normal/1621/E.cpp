// time-limit: 2000
// problem-url: https://codeforces.com/contest/1621/problem/E

// ...

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library CeilDiv.h ====
auto ceilDiv(auto a, auto b){
	return (a+b-1)/b;
}

// } ==== End library CeilDiv.h ====
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int numTeach; std::cin>>numTeach;
	int numGroup; std::cin>>numGroup;
	assert(numTeach>=numGroup);
	std::vector<int> teachers(numTeach);
	for(auto& it: teachers) {
		std::cin>>it;
	}
	std::sort(begin(teachers), end(teachers));
	teachers.erase(teachers.begin(), teachers.end()-numGroup);
	numTeach=-1;
	
	struct Group{
		std::vector<int> values;
		int64_t sum;
	};
	std::vector<Group> groups(numGroup);
	for(auto& group: groups){
		int size; std::cin>>size;
		group.values.resize(size);
		for(auto& it: group.values) {
			std::cin>>it;
			group.sum+=it;
		}
	}

	std::vector<int> averages(groups.size()); // take ceil (need average  teacher)
	std::transform(begin(groups), end(groups), averages.begin(),
			[&](auto const& it)->int{
				return (int)ceilDiv(it.sum, (int)it.values.size());
			});
	std::sort(begin(averages), end(averages));

	std::vector<int> goodData(averages.size()+1), goodLeftData(averages.size()+1), goodRightData(averages.size());
	for(int index=0; index<(int)averages.size(); ++index){
		goodData[index]=averages[index]<=teachers[index];
	}
	for(int index=1; index<(int)averages.size(); ++index){
		goodLeftData[index]=averages[index]<=teachers[index-1];
		goodRightData[index-1]=averages[index-1]<=teachers[index];
	}

	std::partial_sum(goodData.rbegin()+1, goodData.rend(), goodData.rbegin()+1);
	std::partial_sum(goodLeftData.rbegin()+1, goodLeftData.rend(), goodLeftData.rbegin()+1);
	std::partial_sum(goodRightData.rbegin()+1, goodRightData.rend(), goodRightData.rbegin()+1);

	auto const good=[&](int left, int right){
		// this segment of indices in average is all  corresponding elements in teachers array?
		assert(0<=left and left<=right and right<=(int)averages.size());
		return goodData[left]-goodData[right]==right-left;
	};
	auto const goodLeft=[&](int left, int right){
		// this segment of indices in average is all  corresponding (index-1) elements in teachers array?
		assert(1<=left and left<=right and right<=(int)averages.size());
		
		return goodLeftData[left]-goodLeftData[right]==right-left;
		
	};
	auto const goodRight=[&](int left, int right){
		assert(0<=left and left<=right and right<=(int)averages.size()-1);
		
		return goodRightData[left]-goodRightData[right]==right-left;
	};


	for(auto const& group: groups){
		auto const average=(int)ceilDiv(group.sum,(int)group.values.size());
		auto const averageIndex=int(std::lower_bound(begin(averages), end(averages), average)-begin(averages));
		assert(averages[averageIndex]==average);

		for(auto studentAge: group.values){
			auto const newAverage=(int)ceilDiv(group.sum-studentAge,(int)group.values.size()-1);
			auto const newAverageIndex=int(std::lower_bound(begin(averages), end(averages), newAverage)-begin(averages));

			bool result;
			if(newAverageIndex>averageIndex){
				result=good(0, averageIndex) and newAverage<=teachers[newAverageIndex-1] and
					good(newAverageIndex, (int)averages.size()) and goodLeft(averageIndex+1, newAverageIndex);
			}else{
				result=good(0, newAverageIndex) and newAverage<=teachers[newAverageIndex] and
					good(averageIndex+1, (int)averages.size()) and goodRight(newAverageIndex, averageIndex);
			}

			assert(([&]{
				auto tmp=averages;
				tmp.erase(std::find(begin(tmp), end(tmp), average));
				tmp.push_back(newAverage);
				assert(tmp.size()==teachers.size());
				std::sort(begin(tmp), end(tmp));

				auto naive=true;
				for(int index=0; index<(int)tmp.size(); ++index)
					if(tmp[index]>teachers[index]){naive=false; break;}

				assert(naive==result);

				return true;
			}()));
			std::cout<<char('0'+result);
		}
	}
	std::cout<<'\n';
}
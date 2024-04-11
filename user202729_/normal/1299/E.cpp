// [I didn't read the editorial]
// As usual, the basic idea is simple (recursively solve smaller problem), 
// but it's hard to come up with the correct details.
//
// Failed idea: try to split by mod 2, then mod 3, mod 5, etc.
// (obviously 2*3*5*...(at least 800) is larger than 18)
// Another failed idea: treat a large block as one item (only work with powers of 2)
//
// Have to write a test case generator. Find out a logical error or two.
// Sometimes I kind of have to "try to swap 0 and 1 here to see which one passes the test cases"
// should work well now.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#define CHECK 0
#if CHECK
std::vector<int> a;
#endif

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len; std::cin>>len;
#if CHECK
	a.resize(len);for(auto & item: a) std::cin>>item;
	a.insert(begin(a), 0);
#endif
	std::vector<std::vector<int>> values(1, std::vector<int>(len));
	for(int index=0;index<len;++index) values[0][index]=index+1;

	auto const get=[]{
		std::cout<<std::flush;
		char c; std::cin>>c;
		assert(c=='0' or c=='1');
		return c-'0';
	};

	while(2*(int)values.size()<len){
		assert(std::any_of(begin(values),end(values),[](auto const & item){return item.size()>2;}));
		assert(std::all_of(begin(values),end(values),[](auto const & item){return item.size()>=2;}));

		std::vector<std::vector<int>> newValues(values.size()*2);

		std::cout<<"? "<<values.size()*2;
		for(auto const & item: values)
			std::cout<<' '<<item[0]<<' '<<item[1];
		std::cout<<'\n';
		
		auto baseValue=get();
		for(int index=0;index<(int)values.size();++index) {
			std::array<std::vector<int>, 2> partition;
			partition[baseValue].push_back(values[index][1]);
			std::for_each(2+begin(values[index]),end(values[index]),[&](auto value){
				std::cout<<"? "<<values.size()*2;
				for(int j=0;j<(int)values.size();++j) if(j!=index)
					std::cout<<' '<<values[j][0]<<' '<<values[j][1];
				std::cout<<' '<<values[index][0]<<' '<<value<<'\n';
				partition[get()].push_back(value);
			});

			if(partition[0].size()==partition[1].size()){
				if(values[index].size()>=2){
					auto const & group=partition[0].size()>=2 ? partition[0]: partition[1];
					if(group.size()>=2){
						std::cout<<"? "<<values.size()*2;
						for(int j=0;j<(int)values.size();++j) if(j!=index)
							std::cout<<' '<<values[j][0]<<' '<<values[j][1];
						std::cout<<' '<<group[0]<<' '<<group[1]<<'\n';
						if(get())
							std::swap(partition[0], partition[1]);
					}else{
						assert(values[index].size()==3);
						assert(not partition[0].empty() and not partition[1].empty());

						std::cout<<"? "<<values.size()*2;
						for(int j=0;j<(int)values.size();++j) if(j!=index)
							std::cout<<' '<<values[j][0]<<' '<<values[j][1];
						std::cout<<' '<<partition[0][0]<<' '<<partition[1][0]<<'\n';
						if(not get()) // TODO
							std::swap(partition[0], partition[1]);
					}
				}
			}else if(partition[0].size()>partition[1].size())
				std::swap(partition[0], partition[1]);

			// now partition[0] is the vector of the elements in the same group as values[index][0],
			// partition[1] is the rest.
			partition[0].push_back(values[index][0]);
			if(partition[0].size()<partition[1].size()){
				std::swap(partition[0], partition[1]);
			}
			assert(partition[0].size()<=partition[1].size()+1);

#if CHECK
			for(auto const & item: partition)
				for(auto x: item)
					assert((a[x]-a[item[0]])% newValues.size()==0);
#endif

			newValues[index*2]=std::move(partition[0]);
			newValues[index*2+1]=std::move(partition[1]);
		}

		values=std::move(newValues);
	}

	while(values.size()>1){
		std::vector<std::vector<int>> newValues(values.size()/2);
		assert(values.size()%2==0);
		for(int index=0;index<(int)newValues.size();++index) {
			auto & first=values[index*2], & second=values[index*2+1];
			assert(first.size()>=second.size());
			if(second.size()>1){
				auto k=
					first.size()==second.size() ? first.size()*2-1 : 3;
				while((second.size()-k/2)*(k/2)%k==0)k+=2;
				assert(k/2<second.size());

				auto const print=[&](int x){ std::cout<<' '<<x; };
				auto const check=[&]{
					std::cout<<"? "<<k;
					std::for_each(begin(first),begin(first)+(k+1)/2, print);
					std::for_each(begin(second),begin(second)+k/2, print);
					std::cout<<'\n';
					return get();
				};
				if(not check()) std::reverse(begin(second),end(second));

				if(first.size()!=second.size()){ // only 2 choices
					assert(check());
				}else{ // 4 choices
					assert(k==first.size()*2-1);
					assert(check());

					std::cout<<"? "<<k;
					std::for_each(1+begin(first),end(first), print);
					std::for_each(begin(second),end(second), print);
					std::cout<<'\n';
					if(not get()){
						std::reverse(begin(second),end(second));
						std::swap(first, second);
					}
				}
			}
			newValues[index].reserve(first.size()+second.size());
			for(unsigned i=0;i<first.size();++i){
				newValues[index].push_back(first[i]);
				if(i==second.size()) break;
				newValues[index].push_back(second[i]);
			}
			assert(newValues[index].size()==first.size()+second.size());
		}

		values=std::move(newValues);
	}
	assert(values.size()==1);
	std::vector<int> result(len);
	for(int i=0;i<len;++i) result[values[0][i]-1]=i+1;
	if(result[0]>len+1-result[0])
		for(auto & item: result) item=len+1-item;
	std::cout<<'!';
	for(auto x: result) std::cout<<' '<<x;
	std::cout<<'\n';
}
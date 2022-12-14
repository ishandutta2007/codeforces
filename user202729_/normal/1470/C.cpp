// ...? wrong output format? (definitely not very easy to test with interactive problems,
// besides there are other problems too)
// {I definitely didn't take that long to notice the bug. But being distracted by something-else is worse.}
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n, initialValue; std::cin>>n>>initialValue;
	assert(initialValue%2==0);
	int fake=-1; // if>=0, instead of getting from stdin, the data is generated
#if LOCAL
	std::cin>>fake;
	assert(0<=fake); assert(fake<n);
#endif

	int const maxQuestion=1000;
	std::vector<int> data(std::min(n, maxQuestion*2+10), initialValue), tmp;
	int curSimulate=0;
	auto const advance=[&]{
		++curSimulate;
		tmp.assign(data.size(), 0);
		assert(data.size()>=4);
		auto const process=[&](int x, int& y, int& z){
			y+=x>>1; z+=x-(x>>1);
		};

		for(int i=1; i<=data.size()-2; ++i) process(data[i], tmp[i-1], tmp[i+1]);
		tmp[1]+=data[0]; //process(data[0], tmp.back(), tmp[1]); // assume [0] is the impostor
		process(data.back(), tmp.end()[-2], tmp[0]);
		std::swap(data, tmp);
	};

	auto const getData=[&](int i){
		assert(0<=i); assert(i<n);
		auto const cut=int(data.size()/2);
		if(i<cut) return data[i];
		if(i>=n-((int)data.size()-cut)) return data[i+data.size()-n];
		return initialValue;
	}; // (how complex.) (required because the simulation is truncated.)

	int numAsked=0;
	auto const subtract=[&](int i, int j){ i-=j; return i<0 ? i+n: i; };
	auto const ask=[&](int pos)->int{
		assert(0<=pos); assert(pos<n);
		int value;
		++numAsked;
		assert(numAsked<=maxQuestion);

		std::cout<<"? "<<pos+1<<'\n'<<std::flush;
		if(fake>=0){
			assert(curSimulate==numAsked-1);
			value=getData(subtract(pos, fake));
		}else
			std::cin>>value;
		assert(std::cerr<<"ask : "<<pos<<" -> "<<value<<'\n');
		//for(int i=0; i<n; ++i) assert(std::cerr<<getData(i)<<' ');
		assert(std::cerr<<'\n');

		return value;
	};

	if(0){
		ask(0);
		advance();
		ask(0);
		advance();
		ask(0);
		advance();

		return 0;
	}


	std::vector<int> candidates; // empty: all candidates

	auto const filterCandidates=[&](
			int numAsked, // corresponding to (value)
			int i, int value){
		assert(numAsked==curSimulate);

		if(candidates.empty()){
			assert(value!=initialValue);
			bool seen=false;
			auto const process=[&](int j){
				if(fake==subtract(i, j)) {
					seen=true;
					assert(value==getData(j));
				}
				if(value==getData(j)) candidates.push_back(subtract(i, j));
			};
			for(int j=0; j<=maxQuestion+1; ++j){
				process(j);
				if(j<n-1-j) process(n-1-j); else break;
				if(j+1==n-1-j) break;
			}
			if(fake>=0) assert(seen);
		}else{
			candidates.erase(std::remove_if(begin(candidates), end(candidates), [&](auto const& candidate){
				return getData(subtract(i, candidate))!=value;
			}), candidates.end());
		}
	};

	for(int _=0; _<maxQuestion/3; ++_){
		auto const tmp=ask(0);
		if(tmp!=initialValue){
			filterCandidates(numAsked-1, 0, tmp);
			advance();
			goto filtered;
		}else if(
				(int)data.size()==n and
				std::count_if(begin(data), end(data), [&](auto const& it){return it==initialValue;})==1){
			assert(getData(0)==initialValue);
			assert(std::cerr<<"Count==1:: special case\n");
			assert(candidates.empty()); candidates.push_back(0);
			advance();
			goto filtered;
		}
		advance();
	}

	if(std::count_if(begin(data), end(data), [&](auto const& it){return it==initialValue;})<=2){
		for(int i=1;; ++i){
			auto const tmp=ask(i);
			if(tmp!=initialValue){
				filterCandidates(numAsked-1, i, tmp);
				advance();
				goto filtered;
			}
			advance();
		}
	}else{ // there are a lot of cells with value equal to initialValue, including the cell at index 0
		// and maxQuestion/3 questions are asked
		for(int i=0;; i+=maxQuestion/3){
			// (observed pattern) the range near the impostor is changed
			assert(std::all_of(data.begin()+1, data.begin()+1+maxQuestion/3,
						[&](auto const& it){return it!=initialValue;}));

			auto const tmp=ask(i);
			if(tmp!=initialValue){
				filterCandidates(numAsked-1, i, tmp);
				advance();
				goto filtered;
			}
			advance();
		}
	}
	assert(false);

filtered:
	assert(not candidates.empty());
	while(candidates.size()>1){
		// choose i somehow

		std::pair<int, int> cur{INT_MAX, INT_MAX};
		auto const maxSet=[&](int i){
			std::unordered_map<int, int> count;
			for(auto candidate: candidates){
				count[getData(subtract(i, candidate))]++;
			}
			if(count.size()==1) return INT_MAX; // actually (number of current candidates), but consider it INT_MAX
			assert(not candidates.empty());
			assert(not count.empty());
			int max=0;
			for(auto [key, value]: count) max=std::max(max, value);
			return max;
		};
		// for an useful i value, subtract(i, candidate) should be near 0 (mod n)
		// <=> -maxQuestion-1 <= i-candidate <= maxQuestion+1
		// <=> -maxQuestion-1+candidate <= i <= maxQuestion+1+candidate
		// somewhat like that.

		for(int i=candidates[0]-2*(maxQuestion+1); i<=candidates[0]+2*(maxQuestion+1); ++i){
			auto const i1=(i%n<0 ? i%n+n: i%n);
			cur=std::min(cur, std::pair(maxSet(i1), i1));
		}
		assert(cur.first!=INT_MAX);

		int const i=cur.second;

		auto const tmp=ask(i);
		filterCandidates(numAsked-1, i, tmp);
		advance();
	}

	if(fake>=0) assert(candidates[0]==fake or not(std::cerr<<"error. "<<candidates[0]<<' '<<fake<<'\n'));
	std::cout<<"! "<<candidates[0]+1<<'\n';
}
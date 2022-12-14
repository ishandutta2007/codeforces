/*
 * Failed main test on problem A? Really? ...
 * Computed rating change:
 * | Point | Rank | Old rating | Delta | New rating |
 * | 2808  | 52   | 2616       | -16   | 2600       | <-- actual
 * | 3283  | 43   | 2616       | -3    | 2613       | <-- +475 pt from problem A
 * However, the rating value changes over time (which means I should get a small
 * rating gain nowadays with the same performance)
 *
 * <s>The pretests appear to be weak.</s>
 * Test 8 is the first non-pretest test case, but not a challenge test case.
 */

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nfloor,nsect,nstair,nelev,elevspeed;
	std::cin>>nfloor>>nsect>>nstair>>nelev>>elevspeed;
	std::vector<int> stairpos(nstair); for(int& x:stairpos)std::cin>>x;
	std::vector<int> elevpos(nelev); for(int& x:elevpos)std::cin>>x;

	int nquery;std::cin>>nquery;
	for(int z=nquery;z--;){
		int x1,y1,x2,y2;
		std::cin>>x1>>y1>>x2>>y2;

		int const floordiff=std::abs(x1-x2);
		auto const [sectmin,sectmax]=std::minmax(y1,y2);
		if(floordiff==0){ std::cout<<sectmax-sectmin<<'\n'; continue; }

		int time=INT_MAX;
		if(not stairpos.empty()){ // try using stair
			auto iter=std::lower_bound(begin(stairpos),end(stairpos),sectmin);
			int nsectextra;
			if(iter==end(stairpos)){
				--iter;
				assert(*iter<sectmin);
				nsectextra=sectmin-*iter;
			}else if(*iter>sectmax){
				nsectextra=*iter-sectmax;
				if(iter!=begin(stairpos)){
					--iter;
					assert(*iter<sectmin);
					nsectextra=std::min(nsectextra,sectmin-*iter);
				}
			}else{
				assert(sectmin<=*iter and *iter<=sectmax);
				nsectextra=0;
			}

			assert(nsectextra>=0);
			time=std::min(time,nsectextra*2+sectmax-sectmin+floordiff);
		}

		if(not elevpos.empty()){ // try using elevator
			auto iter=std::lower_bound(begin(elevpos),end(elevpos),sectmin);
			int nsectextra;
			if(iter==end(elevpos)){
				--iter;
				assert(*iter<sectmin);
				nsectextra=sectmin-*iter;
			}else if(*iter>sectmax){
				nsectextra=*iter-sectmax;
				if(iter!=begin(elevpos)){
					--iter;
					assert(*iter<sectmin);
					nsectextra=std::min(nsectextra,sectmin-*iter);
				}
			}else{
				assert(sectmin<=*iter and *iter<=sectmax);
				nsectextra=0;
			}

			assert(nsectextra>=0);
			time=std::min(time,nsectextra*2+sectmax-sectmin+(floordiff+elevspeed-1)/elevspeed);
		}

		std::cout<<time<<'\n';
	}
}
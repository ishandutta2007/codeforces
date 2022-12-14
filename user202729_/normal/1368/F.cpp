// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	int optimal=-1;
	while(optimal<number){
		++optimal;
		for(int i=1; i<number-optimal; ++i)
			if((optimal+i-1)/(number-optimal-i)+1<i){
				goto continue_outer;
			}
		break;
continue_outer:;
	}

	int strat=1; // positions %strat==1 are left white
	while(
			number-(
				(number-1)/strat+1 // left white
				)-(
					strat-1 // might be removed
					)!=optimal){
		assert(strat<number); // not proven, but stress-tested
		++strat;
	}

	std::vector<char> on(number);
	while(std::accumulate(begin(on), end(on), 0)<optimal){
		std::vector<int> onPositions;
		for(int index=0; index<number; ++index) if(index%strat!=0 and not on[index]){
			onPositions.push_back(index);
			on[index]=true;
			if((int)onPositions.size()==strat) break;
		}

		assert(not onPositions.empty());
		std::cout<<onPositions.size();
		for(auto it: onPositions) std::cout<<' '<<it+1;
		std::cout<<std::endl;

		int value; std::cin>>value;
		if(value==-1) return 0;

		value--;
		for(int delta=0; delta<(int)onPositions.size(); ++delta)
			on[(value+delta)%number]=false;
	}
	std::cout<<"0\n";
}
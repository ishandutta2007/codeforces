// Reimplement everything.
// What can be wrong with this solution?
// (test 71 is not a pretest.)
//
// Could the problem be precision error?
// Long double is an easy change.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t number, chargeSpeed; std::cin>>number>>chargeSpeed;

	struct Device{int64_t useSpeed, initial;};
	std::vector<Device> devices(number);
	int64_t sumUseSpeed{};
	for(auto &[useSpeed, initial]: devices){
		std::cin>>useSpeed>>initial;
		sumUseSpeed+=useSpeed;
	}
	if(chargeSpeed>=sumUseSpeed){std::cout<<"-1\n"; return 0;}
	
	long double result=0;
	// binary search for the answer is probably fast enough
	for(auto [step, counter]=std::pair{std::pow((long double)2, 120), 200}; counter--; step/=2){
		result+=step;
		long double moreEnergy{};
		for(auto const [useSpeed, initial]: devices){
			moreEnergy+=std::max((long double)0, (long double)useSpeed*result-(long double)initial);
		}
		if(moreEnergy<=(long double)chargeSpeed*result){
			// result is okay
		}else
			result-=step;
	}

	std::cout<<std::fixed<<std::setprecision(10)<<(double)result<<'\n';
}
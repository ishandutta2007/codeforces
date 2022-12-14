#include<iostream>
#include<iomanip>

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
4 2 20
)");}
#endif // Sublime


int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
	// ^^^ not necessary

	int64_t cookT,checkT,t;std::cin>>cookT>>checkT>>t;
	int64_t nCheck=(cookT-1)/checkT+1;
	int64_t warmT=nCheck*checkT-cookT;

	// note that the chicken need to be cooked for 2*t minutes while
	// the stove is off

	int64_t warmTEquiv=2*cookT+warmT;
	t*=2;
	double ans=(cookT+warmT)*(t/warmTEquiv);t%=warmTEquiv;
	if(t>2*cookT){
		ans+=cookT;ans+=t-2*cookT;
	}else{
		ans+=t/2.;
	}
	std::cout<<std::setprecision(1)<<std::fixed<<ans<<'\n';
}
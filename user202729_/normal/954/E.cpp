#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
2 12
1 3
10 15
)");}
#endif // Sublime

int main(){
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	int n_tap,desired_temp;
	std::cin>>n_tap>>desired_temp;

	std::vector<std::pair<int,double>>hot_taps,cold_taps;
	//(-|delta temp|,max amount)

	double ans=0;

	std::vector<int>max_amounts(n_tap);
	for(int&max_amount:max_amounts)std::cin>>max_amount;
	for(int max_amount:max_amounts){
		int temp;std::cin>>temp;
		if(temp==desired_temp)
			ans+=max_amount;
		else if(temp>desired_temp)
			hot_taps.emplace_back(desired_temp-temp,max_amount);
		else
			cold_taps.emplace_back(temp-desired_temp,max_amount);
	}

	std::sort(hot_taps.begin(),hot_taps.end());
	std::sort(cold_taps.begin(),cold_taps.end());

	while(!hot_taps.empty()&&!cold_taps.empty()){
		auto&hot_tap=hot_taps.back();
		auto&cold_tap=cold_taps.back();
		double hot_value=-hot_tap.first*hot_tap.second;
		double cold_value=-cold_tap.first*cold_tap.second;
		if(hot_value==cold_value){
			ans+=hot_tap.second+cold_tap.second;
			hot_taps.pop_back();cold_taps.pop_back();
		}else if(hot_value>cold_value){
			ans+=cold_tap.second+hot_tap.second*cold_value/hot_value;
			hot_tap.second*=1-cold_value/hot_value;
			cold_taps.pop_back();
		}else{
			ans+=hot_tap.second+cold_tap.second*hot_value/cold_value;
			cold_tap.second*=1-hot_value/cold_value;
			hot_taps.pop_back();
		}
	}

	std::cout<<std::fixed<<std::setprecision(10)<<ans<<'\n';
}
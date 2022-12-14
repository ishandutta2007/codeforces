#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
6
2
4 6 3 3 5 6
2 6 3 6 5 3

)");}
#endif // Sublime

#include<iostream>
#include<iomanip>
#include<vector>
int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
	int nplanet,payload_weight;
	std::cin>>nplanet>>payload_weight;
	std::vector<int>lift(nplanet),land(nplanet);
	for(int&x:lift){
		std::cin>>x;
		if(x==1){std::cout<<"-1\n";return 0;}
	}
	for(int&x:land){
		std::cin>>x;
		if(x==1){std::cout<<"-1\n";return 0;}
	}

	double weight=payload_weight;
	for(int i=nplanet,j=0;i-->0;j=i){
		// current weight: (weight)

		// todo: undo {land j}
		weight*=land[j];weight/=land[j]-1;
		// todo: undo {lift i}
		weight*=lift[i];weight/=lift[i]-1;
	}
	std::cout<<std::setprecision(10)<<std::fixed;
	std::cout<<weight-payload_weight<<'\n';
}
// forgot to check submission result (!?)
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int n; std::cin>>n;
	std::vector<int> xCoordinates, yCoordinates;
	xCoordinates.reserve(n);
	yCoordinates.reserve(n);
	for(int _=0; _<n*2; ++_){
		int x, y; std::cin>>x>>y;
		if(x==0) yCoordinates.push_back(std::abs(y));
		else xCoordinates.push_back(std::abs(x));
	}
	std::sort(begin(xCoordinates), end(xCoordinates));
	std::sort(begin(yCoordinates), end(yCoordinates));
	double result{};
	for(int i=0; i<n; ++i)
		result+=std::sqrt((double)xCoordinates[i]*xCoordinates[i]+(double)yCoordinates[i]*yCoordinates[i]);
	std::cout<<std::fixed<<std::setprecision(11)<<result<<'\n';
}
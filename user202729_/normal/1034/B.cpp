#include<iostream>
#ifdef Sublime
#include<sstream>
std::stringstream I(R"(
2 2
3 3
2 7
3 3
5 5
4 7
)");
#else
auto&I=std::cin;
#endif
auto&O=std::cout;

#include<vector>
#include<algorithm>

std::vector<std::vector<int>> data={{
	{},
	{0,1},
	{0,2,4},
	{0,3,2,1},
	{0,2,0,0,0}
}};

int main(){
	int n,m;
	while(I>>n>>m){
		if(n<m)std::swap(n,m);
		int diff;
		if(n<5)
			diff=data[n][m];
		else if(n==7&&m==2)
			diff=2;
		else if(m==1){
			int n1=n%6;
			if(n1<=3)diff=n1;
			else diff=6-n1;
		}else
			diff=n&m&1;
		O<<(long long)n*m-diff<<'\n';
	}
}
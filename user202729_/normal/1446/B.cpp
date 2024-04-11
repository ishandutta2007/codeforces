#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int lena, lenb; std::cin>>lena>>lenb;
	std::string a, b; std::cin>>a>>b;
	assert((int)a.size()==lena);
	assert((int)b.size()==lenb);
	std::vector f(a.size()+1, std::vector<int>(b.size()+1));
	int result{};
	for(int i=(int)a.size(); i--;)
		for(int j=(int)b.size(); j--;)

			result=std::max(result,
					f[i][j]=std::max({
						a[i]==b[j] ? f[i+1][j+1]+2: 0,
						f[i+1][j]-1,
						f[i][j+1]-1,
					}));
	std::cout<<result<<'\n';

}
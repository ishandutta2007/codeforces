#include<iostream>
#include<vector>
#include<climits>
#include<array>
#include<numeric>

#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	std::array<std::array<int,20>,20> cost{};
	char last;std::cin>>last;last-='a';
	for(int _=n-1;_--;){
		char cur;std::cin>>cur;cur-='a';
		if(cur!=last){
			//++cost[std::min(last,cur)][std::max(last,cur)];
			++cost[last][cur];
			++cost[cur][last];
		}
		last=cur;
	}

	std::vector<int> f(1<<m);
	f[0]=0;
	for(int mask=1;mask<(1<<m);++mask){
		int cur=INT_MAX;
		int const dist=m-__builtin_popcount(mask);
		for(int bit=0;bit<m;++bit)if(mask>>bit&1){
			int newf=f[mask^(1<<bit)];
			for(int j=0;j<m;++j)
				if(mask>>j&1)
					newf-=dist*cost[j][bit];
				else
					newf+=dist*cost[j][bit];

			cur=std::min(cur,newf);
		}
		f[mask]=cur;
	}

	std::cout<<f.back()<<'\n';
}
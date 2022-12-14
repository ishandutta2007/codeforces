#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	std::vector<int> phi(n+1);
	for(int i=n;i;--i)
		phi[i]=i;

	for(int i=2;i<=n;++i)
		if(phi[i]==i){
			for(int j=i;j<=n;j+=i)
				phi[j]=phi[j]/i*(i-1);
		}

	int k;std::cin>>k;

	std::vector<std::pair<int,int>> a(n);
	for(int i=n;i--;)
		a[i]={phi[i+1],i+1};
	std::sort(begin(a),end(a));

	// case 1: k+2 numbers including 2

	int64_t s1=0;
	for(int i=k+2;i--;)
		s1+=a[i].first;
	int64_t ans=s1;

	// case 2: k+1 (!= 0) numbers not including 2
	int64_t s2=0;
	for(int i=0,cnt=k+1;;++i){
		if(i>n){
			std::cout<<ans<<'\n';
			return 0;
		}
		if(a[i].second&1){
			s2+=a[i].first;
			if(0==--cnt)
				break;
		}
	}

	ans=std::min(ans,s2);
	std::cout<<ans<<'\n';
}
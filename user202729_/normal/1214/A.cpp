#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,d,e;std::cin>>n>>d>>e;
	e*=5;
	int g=std::__gcd(d,e);
	d/=g;e/=g;
	int nmod=n%g,ndiv=n/g;

	int ans=0;
	if(ndiv>=d*e){
		ans=ndiv;
	}else{
		for(int nd=0;nd<=e;++nd){
			int x=nd*d;
			if(x<=ndiv){
				int y=(ndiv-x)/e*e+x;
				assert(y<=ndiv);
				ans=std::max(ans,y);
			}
		}
	}

	std::cout<<n-(ans*g)<<'\n';
}
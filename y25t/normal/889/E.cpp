#include<bits/stdc++.h>
#define ll long long
#define N 100005

int n;
ll a;

std::map<ll,ll> f;

int main(){
	scanf("%d%lld",&n,&a);
	f[a-1]=0;
	for(int i=1;i<n;i++){
		scanf("%lld",&a);
		while(1){
			auto it=f.lower_bound(a);
			if(it==f.end())
				break;
			auto [x,y]=*it;
			f.erase(it);
			ll t=x/a;
			f[a-1]=std::max(f[a-1],y+(t-1)*a*i);
			f[x%a]=std::max(f[x%a],y+t*a*i);
		}
	}
	ll ans=0;
	for(auto [x,y]:f)
		ans=std::max(ans,x*n+y);
	printf("%lld\n",ans);
}
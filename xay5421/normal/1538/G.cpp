// author: xay5421
// created: Thu Jun 10 22:36:33 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
int T,x,y,a,b;
LL sol(int x,int y,int a,int b){
	if(a==b)return min(x,y)/a;
	if(a<b)swap(a,b);
	auto chk=[&](LL mid)->bool{
		if(mid*b>x)return 0;
		LL tmp=min(mid,(x-mid*b)/(a-b));
		assert(tmp*a+(mid-tmp)*b<=x);
		return (mid-tmp)*a+tmp*b<=y;
	};
	LL l=0,r=2e9,ans=0;
	while(l<=r){
		LL mid=(l+r)>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		printf("%lld\n",sol(x,y,a,b));
	}
	return 0;
}
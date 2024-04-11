#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,a,b,c,d;
inline int calc(int x){
	int t=x,ans=x*a;
	if (c%d==0)t-=c/d;
	else t-=c/d+1;
	t=max(0ll,t);
	ans-=t*b*c;
	ans-=(x-t)*((x-t)-1)*d/2*b;
	return ans;
}
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (a>b*c){
			puts("-1");
			continue;
		}
		int l=1,r=2e6;
		while (l<r){
			int mid=(l+r+1)/2;
			if (calc(mid)>calc(mid-1))l=mid;
			else r=mid-1;
		}
		printf("%lld\n",calc(l));
	}
}
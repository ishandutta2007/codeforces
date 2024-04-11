#include <bits/stdc++.h>
using namespace std;

long long n, i, x, lo, hi, ans;
int main(){
	for(scanf("%lld",&n),i=1;i<=n;i++){
		scanf("%lld",&x); ans=0;
		lo = 1; hi = 65000;
		while(lo < hi){
			long long m=lo+hi>>1;
			ans=max(ans,x-1-m+min(x-1-m,m*(m+1)/2));
			if(x-1-m>m*(m+1)/2) lo=m+1;
			else hi=m;
		}
		ans=max(ans,x-1-lo+min(x-1-lo,lo*(lo+1)/2));
		ans = max(ans, x-1);
		printf("%lld\n",ans);
	}
	getchar(); getchar();
}
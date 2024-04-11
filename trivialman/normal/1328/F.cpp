#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
const int INF = (1<<30)-1;
const double pi = acos(-1);
mt19937 rng(time(0));

LL n, k, ans = 1e15, sum, cnt, a[N], s[N];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%lld%lld",&n,&k);
	rep(i,1,n) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	rep(i,1,n) s[i] = s[i-1]+a[i];
	rep(i,1,n){
		cnt = a[i]==a[i-1] ? cnt+1 : 1;
		sum = a[i]*(i-1) - s[i-1] + (s[n]-s[i]) - a[i]*(n-i) - n + k;
		if(cnt>=k) sum = 0;
		if(i>=k) sum = min(sum, a[i]*(i-1) - s[i-1] - (i-k));
		if(i<=n-k+1) sum = min(sum, (s[n]-s[i]) - a[i]*(n-i) - (n-i+1-k));
		ans = min(ans, sum);
	}
	printf("%lld\n",max(ans,0ll));
	return 0;
}
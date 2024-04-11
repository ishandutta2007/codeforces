#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e6+5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

LL n, h[N], ans[N], sumh = 0;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld",h+i), sumh += h[i];
	
	LL l = 0, r = 1e12+10, beg;
	while(l<=r){
		LL mid = l+r>>1;
		LL tmp = (mid+mid+n-1) * n / 2;
		if (tmp >= sumh) beg = mid, r = mid-1;
		else l = mid+1;
	}
	
	LL x = (beg+beg+n-1) * n / 2 - sumh;
	rep(i,1,n) ans[i] = beg + i - 1;
	rep(i,n-x+1,n) ans[i]--;
	
	rep(i,1,n) printf("%lld ",ans[i]);
	return 0;
}
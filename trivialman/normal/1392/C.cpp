#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 200003;
const int INF = 1e9;
const int N = 3e5+5;
const double PI = acos(-1);
//mt19937 rng(time(0));

int T, n, a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",a+i);
		LL ans = 0;
		rep(i,1,n-1) ans += 1ll * max(0, a[i] - a[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}
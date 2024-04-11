#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 1E6+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL n, k, f[505], g[505];

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	cin>>n>>k;
	f[0] = 0;
	rep(m,1,n){
		memset(g,0,sizeof g);
		g[1] = g[2] = 2;
		rep(i,3,n+1) g[i] = (g[i-1]*2 - (i>m?g[i-m-1]:0) + P) % P;
		f[m] = g[n+1];
	}
	rrep(i,n,1) f[i] = (f[i] - f[i-1] + P) % P;
	LL ans = 0;
	rep(i,1,n) rep(j,1,n){
		if(i * j < k)
			ans = (ans + f[i] * f[j]) % P;
	}
	cout<<ans*(P+1>>1)%P<<endl;
	return 0;
}
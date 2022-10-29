#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const int P = 1e9+7;
const int N = 155, M = 6000;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[N], f[N][M], g[N][M];
int n, k, s, sum;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>k>>s;
	s = min(s, k*(n-k));
	rep(i,1,n) cin>>a[i];
	rep(i,1,k) sum += a[i];
	
	rep(j,k,n) rep(x,0,s) f[j][x] = g[j][x] = sum;
	rrep(i,k,1){
		swap(f, g);
		rep(j,k+1,n){
			rep(x,0,(j-k)*(k-i+1)){
				f[j][x] = min(g[j][x], f[j-1][x]);
				if(x>=(j-i)) f[j][x] = min(f[j][x], g[j-1][x-(j-i)] + a[j] - a[i]);
			}
		}
	}
	int ans = 1e9;
	rep(x,0,s) ans = min(ans, f[n][x]);
	cout<<ans<<endl;
	return 0;
}
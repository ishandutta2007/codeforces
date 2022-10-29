#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
const int P = 1e9+7;
const int N = 3005;

int m, a[N], dp[N*N/2], tr[N*N/2][2], fa[N*N/2];

void add(int &x, int y){ x = x+y>=P ? x+y-P : x+y; }

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>m;
	rep(i,1,m) cin>>a[i];
	
	int ans = 0, T = 0;
	fa[0] = -1, dp[0] = 1;
	rep(r,1,m){
		int u = 0;
		rrep(l,r,1){
			if(tr[u][a[l]]) {u = tr[u][a[l]]; continue;}
			tr[u][a[l]] = ++T, fa[T] = u;
			int k = 0;
			rep(i,0,min(3,r-l)){
				k = k << 1 | a[l+i];
				if(i!=3 || k<14 && k!=3 && k!=5) add(dp[T], dp[u]);
				u = fa[u];
			}
			add(ans, dp[T]);
			u = T;
		}
		cout<<ans<<endl;
	}
}
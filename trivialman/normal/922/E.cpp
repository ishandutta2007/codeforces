#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 10005;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL f[N], g[N], c[N], cost[N];
int n;
LL w, b, x;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>w>>b>>x;
	rep(i,1,n) cin>>c[i];
	rep(i,1,n) cin>>cost[i];
	
	memset(f,-1,sizeof f);
	int s = c[1];
	rep(j,0,s) f[j] = w - cost[1] * j;
	rep(i,2,n){
		swap(f, g);
		memset(f,-1,sizeof f);
		
		s += c[i];
		rep(j,0,s){
			rep(k,0,c[i]){
				if(j<k || g[j-k]<0) continue;
				f[j] = max(f[j], min(g[j-k] + x, w + b * (j-k)) - cost[i] * k);
			}
		}
	}
	rrep(i,s,0) if(f[i]>=0){
		cout<<i<<endl;
		return 0;
	}
	return 0;
}
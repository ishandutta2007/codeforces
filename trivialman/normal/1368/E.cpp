#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int INF = 1e9;
const int N = 2e5+5;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n, m, x, y, in[N], a[N];
vector<int> g[N];
set<int> ans;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		ans.clear();
		rep(i,1,n) g[i].clear(), in[i]=a[i]=0;
		rep(i,1,m) scanf("%d%d",&x,&y), g[x].PB(y), in[y]++;
		
		rep(i,1,n){
			if(a[i]==2) g[i].clear(), ans.insert(i);
			for(auto x:g[i]) a[x] = max(a[x], a[i]+1);
		}
		printf("%d\n", ans.size());
		for(auto x:ans) printf("%d ",x);
		printf("\n");
	}
	
	return 0;
}
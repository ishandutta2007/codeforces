#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 2005;
mt19937 rng(time(0));

vector<int> g[N];
int a[N], sz[N], ans[N];
int n, x, y;
bitset<N> use, bkp[N];

void dfs(int x){
	sz[x] = 1;
	for(auto u:g[x]){
		dfs(u);
		sz[x] += sz[u];
	}
}

void dfs2(int x){
	int cnt = 0;
	rep(i,1,n){
		cnt += use[i];
		if(cnt==a[x]+1){
			ans[x] = i;
			use[i] = 0;
			break;
		}
	}
	//cout<<x<<" "<<a[x]<<" "<<ans[x]<<endl;
	
	bkp[x] = use;
	use = 0;
	int now = 1, last;
	for(auto u:g[x]){
		cnt = 0;
		last = now;
		while(cnt<sz[u]){
			cnt += bkp[x][now];
			now++;
		}
		rep(i,last,now) use[i] = bkp[x][i];
		dfs2(u);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		g[x].PB(i);
		a[i] = y;
	}
	dfs(g[0][0]);
	//rep(i,1,n) cout<<sz[i]<<" ";cout<<endl;
	rep(i,1,n){
		if(a[i]>=sz[i]){
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	
	//cout<<use<<endl;
	use.set();
	dfs2(g[0][0]);
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}
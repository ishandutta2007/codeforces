#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+5;
mt19937 rng(time(0));

int n, m, k, x, y, z, ans = 0;
vector<ar2> g[N];
bitset<N> a[10][10];
int id[10][10];
bool sect[50][50];
int now[10];

void dfs(int n){
	if (n==k+1){
		ans++;
		//rep(i,1,k) cout<<now[i]<<" ";cout<<endl;
		return; 
	}
	rep(i,1,n){
		int id2 = id[n][i];
		if (sect[id2][id2]) continue;
		bool flag = true;
		rep(j,1,n-1) {
			int id1 = id[j][now[j]];
			if (sect[id1][id2]) flag = false;
		}
		if (flag){
			now[n] = i;
			dfs(n+1);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		scanf("%d%d%d",&x,&y,&z);
		g[x].PB({z,y});
	}
	
	rep(i,1,k) rep(j,1,i) a[i][j].reset();
	int cnt = 0;
	rep(i,1,k) rep(j,1,i) cnt++, id[i][j] = cnt;
	memset(sect,0,sizeof sect);
	
	rep(i,1,n){
		sort(g[i].begin(), g[i].end());
		int sz = g[i].size();
		rep(j,1,sz){
			int x = g[i][j-1][1], id1 = id[sz][j];
			if (a[sz][j][x]==1) sect[id1][id1] = true;
			a[sz][j][x] = 1;
		}
	}
	/*rep(i,1,k) rep(j,1,i){
		cout<<i<<" "<<j<<" ";
		rep(x,1,n) cout<<a[i][j][x];
		cout<<endl;
	}*/
	
	rep(i,1,k) rep(j,1,i){
		rep(i2,i+1,k) rep(j2,1,i2){
			int id1 = id[i2][j2], id2 = id[i][j];
			sect[id1][id2] = sect[id2][id1] = (a[i][j] & a[i2][j2]).any();
		}
	}
	
	ans = 0;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct hopcroftkarp {
	static const int mxN=1e3;
	vector<int> canMatch[mxN];
	bool used[mxN], vis[mxN];
	int matching[mxN], dist[mxN], qu[mxN];
	bool dfs(int u1) {
		vis[u1]=1;
		for(int v : canMatch[u1]) {
			int u2=matching[v];
			if(u2==-1||!vis[u2]&&dist[u2]==dist[u1]+1&&dfs(u2)) {
				used[u1]=1;
				matching[v]=u1;
				return 1;
			}
		}
		return 0;
	}
	int ac(int n, int m) {
		memset(matching, -1, 4*m);
		int qt, f, t=0;
		while(1) {
			memset(dist, 69, 4*n);
			qt=0;
			for(int i=0; i<n; ++i) {
				if(!used[i]) {
					qu[qt++]=i;
					dist[i]=0;
				}
			}
			for(int i=0; i<qt; ++i) {
				int u1=qu[i];
				for(int v : canMatch[u1]) {
					int u2=matching[v];
					if(u2!=-1&&dist[u2]>=n) {
						dist[u2]=dist[u1]+1;
						qu[qt++]=u2;
					}
				}
			}
			f=0;
			memset(vis, 0, n);
			for(int i=0; i<n; ++i)
				if(!used[i]&&dfs(i))
					++f;
			if(!f)
				break;
			t+=f;
		}
		return t;
	}
} hk;

const int mxN=100, mxA=1e3;
int n, m, d[mxN][mxN], s, b, k, j, ax[mxA], aa[mxA], af[mxA], bx[mxA], bd[mxA];
vector<int> adj[mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(d, 0x3f, sizeof(d));
	for(int s=0; s<n; ++s) {
		d[s][s]=0;
		queue<int> qu;
		qu.push(s);
		while(qu.size()) {
			int u=qu.front();
			qu.pop();
			for(int v : adj[u]) {
				if(d[s][v]>d[s][u]+1) {
					d[s][v]=d[s][u]+1;
					qu.push(v);
				}
			}
		}
	}
	cin >> s >> b >> k >> j;
	for(int i=0; i<s; ++i) {
		cin >> ax[i] >> aa[i] >> af[i], --ax[i];
	}
	for(int i=0; i<b; ++i) {
		cin >> bx[i] >> bd[i], --bx[i];
	}
	for(int i=0; i<s; ++i) {
		for(int j=0; j<b; ++j) {
			if(aa[i]>=bd[j]&&d[ax[i]][bx[j]]<=af[i]) {
				hk.canMatch[i].push_back(j);
			}
		}
	}
	int mt=hk.ac(s, b);
	long long ans=(long long)mt*k;
	for(int i=1; i<=s; ++i) {
		int fake=i, real=min(mt, s-fake);
		ans=min(ans, (long long)fake*j+(long long)real*k);
	}
	cout << ans;
}
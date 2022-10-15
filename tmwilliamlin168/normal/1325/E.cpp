#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, ans=1e9, d[mxN+1], par[mxN+1], qu[mxN+1];
vector<int> adj[mxN+1];
bool vis[mxN+1];

void dfs(int u, int p=-1) {
	if(~p) {
		adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
		d[u]=d[p]+1;
	}
	vis[u]=1;
	for(int v : adj[u]) {
// 		cout << u << " " << v << endl;
		if(vis[v]) {
// 			cout << "ua" << endl;
// 			cout << d[u] << " " << d[v] << endl;
            if(d[u]>=d[v])
			ans=min(d[u]-d[v]+1, ans);
		} else
			dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0, a; i<n; ++i) {
		cin >> a;
		vector<ar<int, 2>> pf;
		for(int j=2; j*j<=a; ++j) {
			if(a%j)
				continue;
			pf.push_back({j, 0});
			while(a%j==0) {
				pf.back()[1]++;
				a/=j;
			}
		}
		if(a>1)
			pf.push_back({a, 1});
		for(int i=(int)pf.size()-1; ~i; --i) {
			if(pf[i][1]%2==0)
				pf.erase(pf.begin()+i);
		}
		while(pf.size()<2)
			pf.push_back({1, 0});
		adj[pf[0][0]].push_back(pf[1][0]);
		adj[pf[1][0]].push_back(pf[0][0]);
	}
	memset(d, 0x3f, sizeof(d));
	for(int i=1; i<=1000; ++i) {
		//if(!vis[i])
			//dfs(i);
		if(vis[i])
			continue;
		int qt=0;
		qu[qt++]=i;
		d[i]=0;
		par[i]=-1;
		for(int qh=0; qh<qt; ++qh) {
			int u=qu[qh];
			bool skp=1;
			for(int v : adj[u]) {
				if(d[v]>1e9) {
					d[v]=d[u]+1;
					qu[qt++]=v;
					par[v]=u;
				} else {
					if(v==par[u]&&skp) {
						skp=0;
					} else
					ans=min(d[u]+d[v]+1, ans);
				}
			}
		}
		for(int j=0; j<qt; ++j)
			d[qu[j]]=d[0];
	}
	cout << (ans<1e9?ans:-1);
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7, I3=333333336;
int n, m, eu[mxN], ev[mxN], ew[mxN], c2, px[mxN];
vector<int> adj[mxN], c;
ll ans=1, ans2, ca;
bool vis[mxN], vis2[mxN];

void dfs(int u, int p) {
	//cout << "D2 " << u << " " << px[u] << endl;
	vis[u]=1;
	for(int e : adj[u]) {
		int v=eu[e]^ev[e]^u;
		if(v==p)
			continue;
		if(vis[v]) {
			if(vis2[e])
				continue;
			vis2[e]=1;
			if(!v) {
				//cout << px[u] << " " << ew[e] << endl;
				c2=px[u]^ew[e];
			} else {
				//cout << u << " " << (px[u]^px[v]^ew[e]) << endl;
				c.push_back(px[u]^px[v]^ew[e]);
			}
		} else {
			px[v]=px[u]^ew[e];
			dfs(v, u);
		}
	}
}

vector<int> gv(vector<int> &c) {
	vector<int> a;
	for(int i=0; i<c.size(); ++i) {
		int j=0;
		while(j<a.size()) {
			c[i]=min(c[i], a[j]^c[i]);
			++j;
		}
		a.push_back(c[i]);
	}
	sort(a.begin(), a.end());
	return a;
}

vector<ar<int, 2>> bmv, s2mv, s1mv;
map<int, int> sm;

void iv(vector<int> &c, int d) {
	int bm=0;
	for(int ci : c)
		bm|=1<<ci;
	//cout << bm << " " << d << endl;
	if(c.size()>2) {
		bmv.push_back({bm, d});
	} else {
		sm[bm]=(sm[bm]+d)%M;
	}
}

vector<int> av(vector<int> a, int b) {
	for(int i=0; i<32; ++i)
		if(b>>i&1) {
			int j=0, x=i;
			while(j<a.size()) {
				x=min(x, x^a[j]);
				++j;
			}
			a.push_back(x);
			if(!x)
				swap(a[0], a.back());
		}
	return a;
}

void dfs2(vector<int> &a, int i, int j) {
	ans2=(ans2+ca)%M;
	if(a.size()<4) {
		//dfs2(a, i+1, j);
		for(; i<s2mv.size(); ++i) {
			vector<int> b=av(a, s2mv[i][0]);
			if(!b[0])
				continue;
			ll da=ca;
			ca=ca*s2mv[i][1]%M;
			dfs2(b, i+1, j);
			ca=da;
		}
	}
	if(a.size()<5) {
		//dfs2(a, i, j+1);
		for(; j<s1mv.size(); ++j) {
			vector<int> b=av(a, s1mv[j][0]);
			if(!b[0])
				continue;
			ll da=ca;
			ca=ca*s1mv[j][1]%M;
			dfs2(b, i, j+1);
			ca=da;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> eu[i] >> ev[i] >> ew[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
	}
	vis[0]=1;
	for(int e : adj[0]) {
		int u=eu[e]^ev[e];
		if(vis[u])
			continue;
		c.clear();
		c2=-1;
		px[u]=ew[e];
		dfs(u, 0);
		if(c2==-1) {
			if(!c.size()) {
				ans=ans*2%M;
			} else {
				vector<int> a=gv(c);
				if(a[0])
					iv(c, 1);
			}
		} else {
			if(c.size()) {
				vector<int> a=gv(c);
				if(a[0]) {
					iv(c, 2);
					c.push_back(c2);
					a=gv(c);
					if(a[0])
						iv(c, 1);
				}
			} else {
				ans=ans*3%M;
				//cout << c2 << endl;
				if(c2) {
					c.push_back(c2);
					iv(c, I3);
				}
			}
		}
	}
	//cout << ans << endl;
	for(pair<int, int> p : sm) {
		//cout << p.first << " " << p.second << "\n";
		if(__builtin_popcount(p.first)==1)
			s1mv.push_back({p.first, p.second});
		else
			s2mv.push_back({p.first, p.second});
	}
	for(ar<int, 2> a : bmv) {
		//cout << a[0] << " " << a[1] << endl;
		vector<int> b;
		b=av(b, a[0]);
		ca=a[1];
		dfs2(b, 0, 0);
	}
	vector<int> b;
	ca=1;
	dfs2(b, 0, 0);
	cout << ans*ans2%M;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e6, Ms=2;
const ll M[Ms]={1000000007, 1000696969}, B1=29, B2=31;

struct hs {
	ll a[Ms]={};
	hs operator*(const ll &o) const {
		hs r;
		for(int i=0; i<Ms; ++i)
			r.a[i]=(a[i]*o)%M[i];
		return r;
	}
	hs operator+(const ll &o) const {
		hs r;
		for(int i=0; i<Ms; ++i)
			r.a[i]=(a[i]+o)%M[i];
		return r;
	}
	bool operator==(const hs &o) const {
		for(int i=0; i<Ms; ++i)
			if(a[i]!=o.a[i])
				return 0;
		return 1;
	}
};

namespace std {
	template<>
	struct hash<hs> {
		inline size_t operator()(const hs &o) const {
			size_t r=0;
			for(int i=0; i<Ms; ++i)
				r=r*B2+o.a[i];
			return r;
		}
	};
}

vector<int> graph[mxN];
bool vis[mxN];
int ans;
string ss[mxN];
unordered_map<hs, int> mp;

bool dfs(int u) {
	vis[u]=true;
	bool childMarked=0;
	for(int v : graph[u])
		if(!vis[v])
			childMarked|=dfs(v);
	if(!childMarked)
		++ans;
	return !childMarked;
}

inline void solve() {
	int n, n2=0;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> ss[i];
		hs h;
		for(int j=0; j<ss[i].size(); ++j) {
			h=h*B1+ss[i][j];
			if(mp.find(h)==mp.end())
				mp[h]=n2++;
		}
	}
	for(int i=0; i<n; ++i) {
		hs h1, h2;
		h1=h1+ss[i][0];
		for(int j=1; j<ss[i].size(); ++j) {
			h1=h1*B1+ss[i][j];
			h2=h2*B1+ss[i][j];
			auto it1=mp.find(h2);
			if(it1!=mp.end()) {
				auto it2=mp.find(h1);
				graph[it1->second].push_back(it2->second);
				graph[it2->second].push_back(it1->second);
			}
		}
	}
	for(int i=0; i<n2; ++i)
		if(!vis[i])
			dfs(i);
	cout << ans << "\n";
	for(int i=0; i<n2; ++i)
		graph[i].clear();
	memset(vis, 0, n2);
	ans=0;
	mp.clear();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}
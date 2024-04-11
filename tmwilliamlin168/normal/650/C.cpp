#include <bits/stdc++.h>
using namespace std;

const int mxNM=1e6;
int n, m, a[mxNM], dp[mxNM], p[mxNM], r[mxNM];
vector<int> graph[mxNM];
pair<int, int> pl[mxNM];

inline int find(int x) {
	return x==p[x]?x:(p[x]=find(p[x]));
}

inline void join(int x, int y) {
	if((x=find(x))==(y=find(y)))
		return;
	if(r[x]<=r[y])
		p[x]=y;
	else
		p[y]=x;
	if(r[x]==r [y])
		++r[y];
}

void cdp(int i) {
	for(int j : graph[i]) {
		if(!dp[j])
			cdp(j);
		dp[i]=max(dp[j], dp[i]);
	}
	++dp[i];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> a[i*m+j];
			pl[j].first=a[i*m+j], pl[j].second=j;
			p[i*m+j]=i*m+j;
		}
		sort(pl, pl+m);
		for(int j=1; j<m; ++j) {
			if(pl[j].first>pl[j-1].first)
				graph[i*m+pl[j].second].push_back(i*m+pl[j-1].second);
			else
				join(i*m+pl[j].second, i*m+pl[j-1].second);
		}
	}
	for(int j=0; j<m; ++j) {
		for(int i=0; i<n; ++i)
			pl[i].first=a[i*m+j], pl[i].second=i;
		sort(pl, pl+n);
		for(int i=1; i<n; ++i) {
			if(pl[i].first>pl[i-1].first)
				graph[pl[i].second*m+j].push_back(pl[i-1].second*m+j);
			else
				join(pl[i].second*m+j, pl[i-1].second*m+j);
		}
	}
	for(int i=0; i<n*m; ++i) {
		if(find(i)!=i) {
			for(int j=0; j<graph[i].size(); ++j)
				graph[find(i)].push_back(graph[i][j]);
			graph[i].clear();
		}
	}
	for(int i=0; i<n*m; ++i)
		if(find(i)==i)
			for(int j=0; j<graph[i].size(); ++j)
				graph[i][j]=find(graph[i][j]);
	for(int i=0; i<n*m; ++i)
		if(find(i)==i&&!dp[i])
			cdp(i);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j)
			cout << dp[find(i*m+j)] << " ";
		cout << "\n";
	}
}
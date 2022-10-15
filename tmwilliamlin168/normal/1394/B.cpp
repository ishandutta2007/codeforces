#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, mxK=9;
int n, m, k, ans;
vector<ar<int, 2>> out[mxN], in[mxN];
bool bad[mxK+1][mxK];
ll con[mxK+1][mxK];

int tn(int i, int j) {
	return i*(i-1)/2+j;
}

//vector<int> p;

void dfs(int i=0, ll bm=0) {
	if(i>=k) {
		++ans;
		//for(int j=0; j<k; ++j)
			//cout << p[j] << " ";
		//cout << endl;
		return;
	}
	for(int j=0; j<=i; ++j) {
		if(bad[i+1][j]||bm&con[i+1][j])
			continue;
		//p.push_back(j);
		dfs(i+1, bm|1ll<<tn(i+1, j));
		//p.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i=0, u, v, w; i<m; ++i) {
		cin >> u >> v >> w, --u, --v;
		out[u].push_back({w, v});
	}
	for(int i=0; i<n; ++i) {
		sort(out[i].begin(), out[i].end());
		for(int j=0; j<out[i].size(); ++j)
			in[out[i][j][1]].push_back({(int)out[i].size(), j});
	}
	for(int i=0; i<n; ++i) {
		sort(in[i].begin(), in[i].end());
		vector<ar<int, 2>> ni;
		for(int j=0; j<in[i].size(); ++j) {
			if(ni.size()&&in[i][j]==ni.back()) {
				bad[in[i][j][0]][in[i][j][1]]=1;
				ni.pop_back();
			} else
				ni.push_back(in[i][j]);
		}
		for(int j=0; j<ni.size(); ++j)
			for(int k=j+1; k<ni.size(); ++k)
				con[ni[k][0]][ni[k][1]]|=1ll<<tn(ni[j][0], ni[j][1]);
	}
	//cout << con[3][0];
	dfs();
	cout << ans;
}
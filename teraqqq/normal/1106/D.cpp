#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m;
bool u[N];

set<int> nodes;
vector<int> mv[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
    	int u, v; cin >> u >> v;
    	mv[u-1].push_back(v-1);
    	mv[v-1].push_back(u-1);
    }

    nodes.insert(0);
    for(int i = 0; i < n; ++i) {
    	int cur = -1;
    	while(cur < 0) {
    		int v = *(nodes.begin());
    		nodes.erase(nodes.begin());
    		if(!u[v]) cur = v;
    	}

    	cout << cur + 1 << ' ';
    	u[cur] = true;
    	for(int to : mv[cur]) {
    		if(!u[to]) nodes.insert(to);
    	}
    }
}
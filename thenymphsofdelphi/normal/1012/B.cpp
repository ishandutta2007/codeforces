#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

int n, m, q;
int par[N];

int root(int u){
    if (par[u] == u){
        return u;
    }
    par[u] = root(par[u]);
    return par[u];
}

void connect(int u, int v){
	par[root(v)] = root(u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	int x, y;
	for (int i = 1; i <= n + m; i++){
	    par[i] = i;
	}
	while (q--){
		cin >> x >> y;
		connect(x, n + y);
	}
	int cnt = -1;
	for (int i = 1; i <= n + m; i++){
	    if (root(i) == i){
	        cnt++;
	    }
	}
	cout << cnt;
}
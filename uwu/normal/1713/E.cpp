#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DisjointSet{
    vector<int> p, sz;
    DisjointSet(int N){
        p.resize(N);
        iota(p.begin(), p.end(), 0);
        sz.resize(N, 1);
    }
    int root(int x){
        return p[x] == x ? x : p[x] = root(p[x]);
    }
    bool unite(int a, int b){
        a = root(a), b = root(b);
        if (a == b) return 0;
        if (sz[b] > sz[a]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return 1;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
	while (T--){
		int N; cin >> N;
		vector<vector<int>> a(N, vector<int>(N));
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j){
			cin >> a[i][j];
		}

		DisjointSet dsu(2 * N);

		for (int i = 0; i < N; ++i){
			for (int j = i + 1; j < N; ++j){
				if (a[i][j] == a[j][i]) continue;
				bool b = a[i][j] > a[j][i];
				int u = (2 * i);
				int v = (2 * j) ^ b;
				if (dsu.root(u^1) == dsu.root(v)){
					if (!b) swap(a[i][j], a[j][i]);
				}
				else{
					dsu.unite(u, v);
					dsu.unite(u^1, v^1);
					if (b) swap(a[i][j], a[j][i]);
				}
			}
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				cout << a[i][j] << " ";
			}
			cout << '\n';
		}
	}
}
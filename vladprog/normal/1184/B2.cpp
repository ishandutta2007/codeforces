#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1000+1, inf = 1e7;

int n, m;
int c[N][N];

vector<int> g[N];
int mt[N];
bool used[N];

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int l, r, k, h;
int xl[N], a[N], f[N];
int xr[N], d[N];

main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            c[i][j] = inf;
    for(int i = 0; i < n; ++i)
        c[i][i] = 0;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        c[u][v] = 1;
        c[v][u] = 1;
    }
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(c[i][k] != inf && c[k][j] != inf)
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    cin >> l >> r >> k >> h;
    for(int i = 0; i < l; ++i)
        cin >> xl[i] >> a[i] >> f[i];
    for(int i = 0; i < r; ++i)
        cin >> xr[i] >> d[i];
    for(int i = 0; i < l; ++i)
        for(int j = 0; j < r; ++j)
            if(c[xl[i]][xr[j]] <= f[i] && d[j] <= a[i])
                g[i].push_back(j);
    for(int i=0;i<r;i++)
        mt[i]=-1;
    int res = 0;
    for(int v=0;v<l;v++){
        for(int i=0;i<l;i++)
            used[i]=0;
        res += try_kuhn(v);
    }
    cout << min(h*l, k*res) << '\n';

}
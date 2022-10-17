#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n;
std::vector<PII> A;
std::map<int, std::vector<PII> > X, Y;
std::vector<VI> g;
std::set<PII> edges;

void add_edge(int a, int b){
    if(a > b) std::swap(a, b);
    if(edges.count(MP(a, b))) return;
    edges.insert(MP(a, b));
    g[a].push_back(b);
    g[b].push_back(a);
}

bool cyclic;
std::set<int> dx, dy;
std::vector<bool> vis;

void dfs(int v, int par=-1){
    vis[v] = true;
    dx.insert(A[v].X);
    dy.insert(A[v].Y);
    TRAV(ch, g[v]) if(ch != par){
        if(vis[ch]) cyclic = true;
        else dfs(ch, v);
    }
}
const int MOD = 1000000007;
int modpow(int a, int e){
    if(e == 0) return 1;
    int t = modpow(a, e/2);
    t = (1ll*t*t)%MOD;
    if(e&1) return (1ll*t*a)%MOD;
    return t;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
    std::cin >> n;
    A.resize(n);
    FOR(i, n) std::cin >> A[i].X >> A[i].Y;
    FOR(i, n){
        X[A[i].X].push_back(MP(A[i].Y, i));
        Y[A[i].Y].push_back(MP(A[i].X, i));
    }
    g.resize(n);
    TRAV(pr, X){
        std::sort(pr.Y.begin(), pr.Y.end());
        FOR(i, SZ(pr.Y)-1) add_edge(pr.Y[i].Y, pr.Y[i+1].Y);
    }
    TRAV(pr, Y){
        std::sort(pr.Y.begin(), pr.Y.end());
        FOR(i, SZ(pr.Y)-1) add_edge(pr.Y[i].Y, pr.Y[i+1].Y);
    }
    int ans = 1;
    vis.resize(n);
    FOR(i, n){
        if(!vis[i]){
            cyclic = false;
            dx.clear();
            dy.clear();
            dfs(i);
            if(cyclic) ans = (1ll*ans*modpow(2, SZ(dx)+SZ(dy)))%MOD;
            else ans = (1ll*ans*(modpow(2, SZ(dx)+SZ(dy))-1))%MOD;
        }
    }
    std::cout << ans;
	return 0;
}
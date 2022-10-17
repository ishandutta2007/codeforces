#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

VI repr, cnt, size;
std::vector<bool> bad;
int n;

std::vector<VI> g;

int Find(int a){
    if(a == repr[a]) return a;
    return repr[a] = Find(repr[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b){
        cnt[a]++;
        return;
    }
    int ind = SZ(repr);
    repr.push_back(ind);
    size.push_back(size[a]+size[b]);
    cnt.push_back(cnt[a]+cnt[b]+1);
    bad.push_back(false);
    repr[a] = ind;
    repr[b] = ind;
    g.emplace_back();
    g[ind].push_back(a);
    g[ind].push_back(b);
    if(cnt[a] < size[a]*(size[a]-1)/2) bad[a] = true;
    if(cnt[b] < size[b]*(size[b]-1)/2) bad[b] = true;
}

const int MOD = 998244353;

VI conv(VI a, VI b){
    VI ret(SZ(a)+SZ(b)-1);
    FOR(i, SZ(a)){
        FOR(j, SZ(b)){
            ret[i+j] = (ret[i+j] + 1ll*a[i]*b[j])%MOD;
        }
    }
    return ret;
}

int tick = 0;
VI dfs(int v){
    VI ret;
    if(SZ(g[v]) != 0){
        assert(SZ(g[v]) == 2);
        ret = conv(dfs(g[v][0]), dfs(g[v][1]));
    }
    if(SZ(ret) < 2) ret.resize(2);
    if(!bad[v]){
        ret[1] = (ret[1]+1)%MOD;
    }
    return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

    std::cin >> n;
    std::vector<PR<int, PII> > edges;
    cnt.resize(n);
    g.resize(n);
    size.resize(n, 1);
    repr.resize(n);
    bad.resize(n);
    FOR(i, n) repr[i] = i;
    FOR(i, n){
        FOR(j, n){
            int a;
            std::cin >> a;
            if(i < j) edges.push_back(MP(a, MP(i, j)));
        }
    }
    std::sort(edges.begin(), edges.end());
    TRAV(i, edges) Union(i.Y.X, i.Y.Y);

    int r = Find(0);
    auto xd = dfs(r);
    REP(i, 1, n+1) std::cout << xd[i] << " ";
    

	return 0;
}
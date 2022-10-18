//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<int>> g;
vector<vector<int>> anc;
vector<int> in, out, d;
int ts = 0;

void dfs(int now, int p){
    anc[now][0] = p;
    in[now] = ts++;
    d[now] = d[p] + 1;
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
    }
    out[now] = ts++;
}

bool isAnc(int a, int b){
    return in[a] <= in[b] && out[a] >= out[b];
}

int lca(int a, int b){
    if(isAnc(a, b)) return a;
    if(isAnc(b, a)) return b;

    int c = a;
    for(int i = 19; i >= 0; i--){
        if(!isAnc(anc[c][i], b)) c = anc[c][i];
    }
    return anc[c][0];
}

int dis(int a, int b){
    int l = lca(a, b);
    return d[a] - d[l] + d[b] - d[l];
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    anc.resize(n + 1, vector<int>(20));
    in.resize(n + 1);
    out.resize(n + 1);
    d.resize(n + 1);

    dfs(1, 1);

    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;

        if(dis(a, x) > dis(a, y)) swap(x, y);

        int la = dis(a, x) + dis(b, y) + 1, lb = dis(a, b), lc = dis(a, y) + dis(b, x) + 1;
        //cerr << la << ' ' << lb << " " << lc << "\n";
        if(k >= la && (k - la) %2 == 0) cout << "YES\n";
        else if(k >= lb && (k - lb) % 2 == 0) cout << "YES\n";
        else if(k >= lc && (k - lc) % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
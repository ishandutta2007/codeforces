//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<int>> g;
vector<int> c, sz;

int n;

void dfs(int now, int p){
    sz[now] = 1;
    int mx = 0;
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
        sz[now] += sz[i];
        mx = max(mx, sz[i]);
    }
    if(mx <= n / 2 && n - sz[now] <= n / 2) c.eb(now);
}

pii leaf(int now, int p, int no){
    for(int i : g[now]){
        if(i == p || i == no) continue;
        return leaf(i, now, no);
    }
    return mp(now, p);
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        cin >> n;

        g.clear();
        g.resize(n + 1);
        c.clear();
        sz.clear();
        sz.resize(n + 1);

        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }

        dfs(1,1);
//        printv(c, cerr);

        if(c.size() == 1){
            pii t = leaf(1, 1, 0);
            cout << t.F << " " << t.S << "\n";
            cout << t.F << " " << t.S << "\n";
            continue;
        }

        pii t1 = leaf(c[0], c[0], c[1]);
        cout << t1.F << " " << t1.S << "\n";
        cout << t1.F << " " << c[1] << "\n";

    }

    return 0;
}
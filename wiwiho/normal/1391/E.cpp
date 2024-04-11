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
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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
vector<vector<int>> dpt;
vector<int> pr, dt;
vector<bool> vst;
int mx = 0;

void dfs(int now, int p, int d){
    dpt[d].eb(now);
    vst[now] = true;
    dt[now] = d;
    pr[now] = p;
    if(dt[mx] < d) mx = now;
    for(int i : g[now]){
        if(vst[i]) continue;
        dfs(i, now, d + 1);
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n, m;
        cin >> n >> m;

        g.clear();
        dpt.clear();
        pr.clear();
        dt.clear();
        vst.clear();
        g.resize(n + 1);
        dpt.resize(n + 1);
        pr.resize(n + 1);
        dt.resize(n + 1);
        vst.resize(n + 1);

        mx = 0;

        for(int i = 0; i < m ;i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }

        dfs(1, 1, 1);

        if(dt[mx] >= (n + 1) / 2){
            vector<int> ans;
            int now = mx;
            ans.eb(now);
            while(pr[now] != now){
                now = pr[now];
                ans.eb(now);
            }
            cout << "PATH\n";
            cout << ans.size() << "\n";
            printv(ans, cout);
            continue;
        }

        vector<pii> ans;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j + 1 < dpt[i].size(); j += 2){
                ans.eb(mp(dpt[i][j], dpt[i][j + 1]));
            }
        }
        cout << "PAIRING\n";
        cout << ans.size() << "\n";
        for(pii i : ans) cout << i.F << " " << i.S <<  "\n";
    }

    return 0;
}
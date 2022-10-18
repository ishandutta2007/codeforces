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
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

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

namespace QAQ{

    set<int> qaq;
    vector<vector<pii>> g;
    int n, m, l, r;
    bool ok = true;

    void dfs(int now, int d){
        if(now == n){
            if(d < l || d > r || qaq.find(d) != qaq.end()){
                cerr << "QAQ " << d << "\n";
                ok = false;
            }
            qaq.insert(d);
        }
        for(pii i : g[now]) dfs(i.F, d + i.S);
    }

    void check(int _l, int _r, int _n, int _m, vector<pair<pii, int>> &e){
        l = _l; r = _r; n = _n; m = _m;
        g.resize(n + 1);
        for(auto i : e){
            g[i.F.F].eb(mp(i.F.S, i.S));
        }
        dfs(1, 0);
        if(qaq.size() != r - l + 1){
            cerr << "QAQ OAO\n";
            ok = false;
        }
        if(ok) cout << "OK\n";
        else cout << "QAQ\n";
    }

}

int l, r;
int len;

int id(int b){
    return 2 + __lg(len) - b;
}

int main(){
    StarBurstStream

    cin >> l >> r;

    if(l == r){
        cout << "YES\n";
        cout << "2 1\n";
        cout << "1 2 " << l << "\n";
        return 0;
    }
    bool tmp = false;
    if(l == 1){
        tmp = true;
        l++;
    }

    len = r - l + 1;
    int n = id(0) + 1;

    vector<pair<pii, int>> ans;
    int now = 0;
    for(int i = __lg(len); i >= 0; i--){
        if(!(1 << i & len)) continue;
        if(l + now - 1) ans.eb(mp(mp(1, id(i)), l + now - 1));
        now += 1 << i;
    }
    for(int i = __lg(len); i >= 0; i--){
        for(int j = i - 1; j >= 0; j--){
            ans.eb(mp(mp(id(i), id(j)), 1 << j));
        }
        ans.eb(mp(mp(id(i), n), 1));
    }
    if(tmp) l--;
    if(l == 1) ans.eb(mp(mp(1, n), 1));

    cout << "YES\n";
    cout << n << " " << ans.size() << "\n";
    for(auto i : ans){
        cout << i.F.F << " " << i.F.S << " " << i.S << "\n";
    }
//    QAQ::check(l, r, n, ans.size(), ans);

    return 0;
}
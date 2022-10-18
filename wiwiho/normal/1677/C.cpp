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

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

void solve(){
    
    int n;
    cin >> n;

    vector<int> ca(n + 1), cb(n + 1);
    vector<vector<int>> g(n + 1);
    /*iota(iter(ca), 0);
    iota(iter(cb), 0);
    mt19937 rnd(clock());
    shuffle(ca.begin() + 1, ca.end(), rnd);
    shuffle(cb.begin() + 1, cb.end(), rnd);
    printv(ca, cerr);
    printv(cb, cerr);*/
    for(int i = 1; i <= n; i++) cin >> ca[i];
    for(int i = 1; i <= n; i++) cin >> cb[i];
    for(int i = 1; i <= n; i++){
        g[ca[i]].eb(cb[i]);
        g[cb[i]].eb(ca[i]);
    }

    /*vector<int> tmp(n + 1);
    iota(iter(tmp), 0);
    ll rans = 0;
    do{
        ll tans = 0;
        for(int i = 1; i <= n; i++){
            tans += abs(tmp[ca[i]] - tmp[cb[i]]);
        }
        //cerr << tans << "  ";
        //printv(tmp, cerr);
        rans = max(rans, tans);
    }
    while(next_permutation(tmp.begin() + 1, tmp.end()));
    cerr << "real " << rans << "\n";*/

    vector<bool> vst(n + 1);
    int sz = 0;
    vector<int> cy;
    function<void(int)> dfs;
    dfs = [&](int now){
        vst[now] = true;
        sz++;
        for(int i : g[now]){
            if(vst[i]) continue;
            dfs(i);
        }
    };
    for(int i = 1; i <= n; i++){
        if(vst[i]) continue;
        sz = 0;
        dfs(i);
        cy.eb(sz);
    }
    gsort(cy);

    int l = 1, r = n + 1;
    int now = 1;
    ll ans = 0;
    for(int i : cy){
        int fst = now;
        for(int j = 1; j < i / 2 * 2; j++){
            int nxt = now == l ? --r : ++l;
            ans += abs(nxt - now);
            //cerr << now << " " << nxt << "\n";
            now = nxt;
        }
        if(i % 2 && i >= 3){
            ans += abs(fst - now);
            //cerr << "odd " << fst << " " << now << "\n";
        }
        else{
            ans += abs(fst - now);
            //cerr << now << " " << fst << "\n";
        }
        now = now == l ? --r : ++l;
    }

    cout << ans << "\n";
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
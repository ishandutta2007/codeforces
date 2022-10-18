
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
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

ll cnt = 0;
void f(vector<pii>& a, int l, int r){
    if(l == r) return;
    int m = (l + r) / 2;
    f(a, l, m);
    f(a, m + 1, r);
    vector<pii> b;

    int lp = l, rp = m + 1;
    while(lp <= m && rp <= r){
        if(a[lp].F <= a[rp].F){
            b.eb(a[lp++]);
        }
        else{
            b.eb(a[rp++]);
            cnt += m - lp + 1;
        }
    }
    while(lp <= m) b.eb(a[lp++]);
    while(rp <= r) b.eb(a[rp++]);
    for(int i = l; i <= r; i++) a[i] = b[i - l];
}

set<pii> now;

void modify(int p){
    auto it = now.lower_bound(mp(p, -MAX));
    if(it == now.end()) return;
    pii tmp = *it;
    it = now.erase(it);
    tmp.S--;
    while(tmp.S < 0 && it != now.begin()){
        it--;
        tmp.S += it->S;
        it = now.erase(it);
    }
    now.insert(tmp);
//    cerr << "modify " << p << "\n";
//    printv(now, cerr);
}

void solve(){
    int n, m;
    cin >> n >> m;
    now.clear();

    vector<pii> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i].F;
        a[i].S = i + 1;
    }
    for(int i = 0; i < m; i++) cin >> b[i];
    cnt = 0;
    f(a, 0, n - 1);
    lsort(b);
//    printv(a, cerr);

    for(int i = 1; i <= n; i++) now.insert(mp(i, 1));
    int ag = 0, ae = 0;
    ll ans = cnt;
    for(int i : b){
//        cerr << "test " << i << " " << ae << " " << ag << "\n";
        while(ae < n && a[ae].F <= i){
            modify(a[ae].S);
            ae++;
        }
        while(ag < n && a[ag].F < i){
            modify(a[ag].S);
            ag++;
        }
//        cerr << "ans " << ag + now.begin()->S << "\n";
        ans += ag + min(0, now.begin()->S);
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
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

    vector<ll> a(n + 1);
    vector<ll> s(n + 1), v(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    ll x;
    cin >> x;
    for(int i = 0; i <= n; i++) v[i] = s[i] - x * i;
    //printv(v, cerr);

    vector<int> dq;
    dq.eb(0);
    vector<int> lp(n + 1);
    lp[1] = 0;
    for(int i = 2; i <= n; i++){
        auto it = lower_bound(iter(dq), i, [&](int a, int b){ return v[a] > v[b]; });
        if(it == dq.begin()) lp[i] = 0;
        else lp[i] = *prev(it) + 1;
        while(!dq.empty() && v[dq.back()] <= v[i - 1]) dq.pob;
        dq.eb(i - 1);
    }
    //printv(lp, cerr);
    
    int l = 0;
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++){
        l = max(l, lp[i]);
        //cerr << "test " << i << " " << l << "\n";
        if(l == 0) dp[i] = i;
        else dp[i] = i - l + dp[l - 1];
    }
    cout << *max_element(iter(dp)) << "\n";

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
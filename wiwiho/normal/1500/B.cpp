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
const ll MAX = 1LL << 60;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

pll exgcd(ll a, ll b){
    if(b == 0){
        return mp(1, 0);
    }
    pll tmp = exgcd(b, a % b);
    return mp(tmp.S, tmp.F - a / b * tmp.S);
}

pll solve(ll a, ll b, ll c){
    bool f1 = a < 0;
    if(a < 0) a *= -1;
    bool f2 = b < 0;
    if(b < 0) b *= -1;

    pll ans = exgcd(a, b);
    if(f1) ans.F *= -1;
    if(f2) ans.S *= -1;

    ll g = __gcd(a, b);

    return mp(ans.F * (c / g), ans.S * (c / g));
}

vector<ll> owo;
ll lcm;

ll calc(ll d){
    ll cnt = 0;
    for(ll i : owo){
        if(i > d) continue;
        cnt += (d - i) / lcm + 1;
    }
    return d - cnt + 1;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;
    ll k;
    cin >> k;

    ll g = __gcd(n, m);
    lcm = (ll) n * m / g;

    vector<int> pos(2 * max(n, m) + 1, -1);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
//        a = i % n + 1;
        pos[a] = i;
    }

    for(int i = 0; i < m; i++){
        int b;
        cin >> b;
//        b = (i + 2) % m + 1;

        if(pos[b] == -1) continue;

        int t1 = pos[b], t2 = i;

        if((t1 - t2) % g != 0) continue;

        pll t = solve(n, -m, t2 - t1);
//        cerr << b << " " << t << "\n";
        ll d = t.F % lcm * n + t1;
        d = (d % lcm + lcm) % lcm;
        owo.eb(d);
    }

    lsort(owo);
    uni(owo);
//    printv(owo, cerr);

    ll l = 0, r = 1e18;
    while(l < r){
        ll mid = (l + r) / 2;
//        cerr << mid << " " << calc(mid) << "\n";
        if(calc(mid) < k) l = mid + 1;
        else r = mid;
    }
    cout << l + 1 << "\n";

    return 0;
}
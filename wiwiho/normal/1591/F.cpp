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

const ll MOD = 998244353;
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

struct seg{
    ll v;
    int l, r;
};

ostream& operator<<(ostream& o, seg s){
    return o << '(' << s.v << ',' << s.l << ',' << s.r << ')';
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<seg> dq;

    ll all = 0;
    ll sum = 0;
    int t = 1;

    for(int i = 1; i <= n; i++){
        
        int a;
        cin >> a;

        ll owo = sum + all * (dq.empty() ? 0 : dq.back().r);
        topos(owo);

        while(!dq.empty() && a < dq.back().r){
            int lst = max(a, dq.back().l - 1);
            ll len = dq.back().r - lst;
            ll v = t * dq.back().v;
            sum -= v * len;
            sum %= MOD;
            if(dq.back().l <= a) dq.back().r = a;
            else dq.pob;
        }

        if(dq.empty() || dq.back().r < a){
            int lst = dq.empty() ? 0 : dq.back().r;
            ll len = a - lst;
            ll v = -all;
            sum += v * len;
            sum %= MOD;
            dq.eb(seg({v * t, lst + 1, a}));
        }

        t *= -1;
        sum *= -1;
        all *= -1;
        all += owo;
        if(i == 1) all++;
        all %= MOD;

        //cerr << "test " << i << " " << all << " " << sum << " " << owo << "\n";
        //printv(dq, cerr);
    }

    ll ans = sum + all * (dq.empty() ? 0 : dq.back().r);
    topos(ans);
    cout << ans << "\n";

    return 0;
}
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

ll fp(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

map<ll, ll> tmp;

ll f(ll t){
    if(tmp.find(t) != tmp.end()) return tmp[t];
    ll ans = fp(2, t - 1);
//    cerr << ans << "\n";
    for(ll i = 1; i * i <= t; i++){
        if(t % i) continue;
        if(i != 1) ans -= f(t / i);//, cerr << f(t / i) << "\n";
        if(i != t / i && t / i != 1) ans -= f(t / (t / i));//, cerr << f(t / (t / i)) << "\n";
        ans = (ans % MOD + MOD) % MOD;
    }
    tmp[t] = ans;
    return ans;
}

int main(){
    StarBurstStream

    ll x, y;
    cin >> x >> y;

    if(y % x){
        cout << "0\n";
        return 0;
    }

    ll t = y / x;

    tmp[1] = 1;
    cout << f(t) << "\n";
//    printv(tmp, cerr);

    return 0;
}
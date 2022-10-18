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

ll inv(ll a){
    return fp(a, MOD - 2);
}

int main(){
    StarBurstStream

    string s;
    cin >> s;
    int n = s.size();

    ll ans = 0;
    ll tmp = 0;
    for(ll i = 0; i < n; i++){

        int d = s[i] - '0';

        ans += (i + 1) * i / 2 % MOD * d % MOD * fp(10, n - i - 1) % MOD;
        ans %= MOD;
//        cerr << d << " " << i << " " << n - i - 1 << "\n";
//        cerr << d * fp(10, n - i - 1) << " " << (i + 1) * i / 2 << " " << tmp << "\n";
    }

    for(ll i = n - 1; i >= 0; i--){
        int d = s[i] - '0';
        tmp = tmp * inv(10) % MOD;
        tmp += inv(10) * (n - i - 1) % MOD;
        tmp %= MOD;
        ans += tmp * fp(10, n - i - 1) % MOD * d % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";

    return 0;
}
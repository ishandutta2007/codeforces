
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

vector<int> prime;
vector<int> p;
void sieve(int n){
    prime.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(prime[i] == 1){
            p.push_back(i);
            prime[i] = i;
        }
        for(int j : p){
            if((ll)i * j > n || j > prime[i]) break;
            prime[i * j] = j;
        }
    }
}

int main(){
    StarBurstStream

    sieve(1000000);

    int n;
    cin >> n;

    vector<ll> dp(n + 1);
    dp[0] = 0;
    ll now = 0;
    for(int i = 1; i <= n; i++){

        ll cnt = 1;
        int tmp = i;
        while(tmp > 1){
            int np = prime[tmp];
            int c = 0;
            while(tmp % np == 0){
                tmp /= np;
                c++;
            }
            cnt *= c + 1;
        }

        dp[i] = now + cnt;
        dp[i] %= MOD;
        now += dp[i];
        now %= MOD;
    }
    cout << dp[n] << "\n";

    return 0;
}
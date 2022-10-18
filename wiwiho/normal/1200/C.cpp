#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

ll gcd(ll a, ll b){
    while(b > 0){
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    StarBurstStream

    ll n, m, q;
    cin >> n >> m >> q;

    ll g = gcd(n, m);
    ll tn = n / g;
    ll tm = m / g;

    while(q--){
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sy--; ey--;
        ll ss = sx == 1 ? sy / tn : sy / tm;
        ll se = ex == 1 ? ey / tn : ey / tm;
        if(ss == se) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
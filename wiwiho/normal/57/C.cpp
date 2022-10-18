//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


ll inv(ll n){
    ll now = 1;
    ll base = n;
    ll p = MOD - 2;
    while(p > 0){
        if(p & 1) now = now * base % MOD;
        base = base * base % MOD;
        p >>= 1;
    }
    return now;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> f(2 * n);
    f[0] = 1; f[1] = 1;
    for(int i = 2; i < 2 * n; i++) f[i] = f[i - 1] * i % MOD;

    cout << ((f[2 * n - 1] * inv(f[n - 1] * f[n] % MOD) % MOD * 2 - n) % MOD + MOD) % MOD << "\n";

    return 0;
}

//      *   *  *****  *   *  *   *
//     *   *  *      **  *  *   *
//    *****  *****  * * *  *   *
//   *   *      *  *  **  *   *
//  *   *  *****  *   *   ***

//      *   * ***** *   * ***** *   * *****
//     *   *   *   *   *   *   *   * *   *
//    *   *   *   *   *   *   ***** *   *
//   * * *   *   * * *   *   *   * *   *
//   * *  *****  * *  ***** *   * *****
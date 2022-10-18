//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pii> a(n);
    map<int, int> cnt1, cnt2;
    map<pii, int> cnt12;
    for(int i = 0; i < n; i++){
        cin >> a[i].F >> a[i].S;
        cnt1[a[i].F]++;
        cnt2[a[i].S]++;
        cnt12[a[i]]++;
    }

    vector<ll> f(n + 1);
    f[0] = 1; f[1] = 1;
    for(int i = 2; i <= n; i++) f[i] = f[i - 1] * i % MOD;

    ll t1 = 1;
    for(pii p : cnt1) t1 = t1 * f[p.S] % MOD;

    ll t2 = 1;
    for(pii p : cnt2) t2 = t2 * f[p.S] % MOD;

    ll t12 = 1;
    lsort(a);
    for(int i = 0; i < n - 1; i++){
        if(a[i].S > a[i + 1].S){
            t12 = 0;
            break;
        }
    }
    if(t12) for(auto p : cnt12) t12 = t12 * f[p.S] % MOD;

    cout << ((f[n] - t1 - t2 + t12) % MOD + MOD) % MOD << "\n";

    return 0;
}
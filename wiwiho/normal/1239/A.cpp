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
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

ll calc1D(int n){
    vector<ll> dp10(n);
    vector<ll> dp01(n);
    vector<ll> dp00(n);
    vector<ll> dp11(n);

    dp10[0] = 1;
    dp01[0] = 1;

    for(int i = 1; i < n; i++){
        dp10[i] = (dp01[i - 1] + dp11[i - 1]) % MOD;
        dp01[i] = (dp00[i - 1] + dp10[i - 1]) % MOD;
        dp00[i] = dp10[i - 1];
        dp11[i] = dp01[i - 1];
    }

    return (dp10[n - 1] + dp01[n - 1] + dp00[n - 1] + dp11[n - 1]) % MOD;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    //cerr << calc1D(n) << "\n";
    //cerr << calc1D(m) << "\n";
    cout << ((calc1D(n) + calc1D(m) - 2) % MOD) << "\n";

    return 0;
}
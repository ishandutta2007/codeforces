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

int main(){
    StarBurstStream

    int n, c;
    cin >> n >> c;

    vector<ll> a(n), b(n);
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) cin >> b[i];

    vector<ll> dp1(n), dp2(n); //1:stair 2:elevator
    vector<ll> ans(n);
    dp2[0] = c;
    for(int i = 1; i < n; i++){
        dp1[i] = min(dp1[i - 1], dp2[i - 1]) + a[i];
        dp2[i] = min(dp1[i - 1] + c + b[i], dp2[i - 1] + b[i]);
        ans[i] = min(dp1[i], dp2[i]);
    }
    //printv(dp1, cerr);
    //printv(dp2, cerr);
    printv(ans, cout);

    return 0;
}
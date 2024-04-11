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
const ll MAX = (1LL << 60);

int main(){
    StarBurstStream

    int n;
    cin >> n;
    vector<int> a(n), f(n, 1), b(n, 1);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 1;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]) b[i] = b[i - 1] + 1;
        ans = max(ans, b[i]);
    }

    for(int i = n - 2; i >= 0; i--){
        if(a[i] < a[i + 1]) f[i] = f[i + 1] + 1;
        ans = max(ans, f[i]);
    }

    for(int i = 0; i < n; i++){
        int fr = i == n - 1 ? 0 : f[i + 1];
        int bk = i == 0 ? 0 : b[i - 1];
        if(i == 0 || i == n || a[i - 1] < a[i + 1]) ans = max(ans, fr + bk);
    }

    cout << ans << "\n";

    return 0;
}
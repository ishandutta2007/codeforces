//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
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
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 10007;
const ll MAX = 1LL << 60;

int main(){
    StarBurstStream

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    lsort(a);

    double ans = 0;
    for(int i = 0; i <= min(m, n - 1); i++){
        if(i > 0) sum -= a[i - 1];
        ans = max(ans, (double)(sum + min((ll)m - i, (ll)(n - i) * k)) / (n - i));
    }
    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}
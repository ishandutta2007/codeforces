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

    int T;
    cin >> T;

    while(T--){

        int n, p, k;
        cin >> n >> p >> k;

        vector<int> a(n + 1);
        for(int i = 1;i <= n; i++) cin >> a[i];
        lsort(a);

        vector<ll> dp1(n + 1, -1), dp2(n + 1, -1);
        dp1[0] = 0; dp2[0] = 0;

        int ans = 0;
        for(int i = 1; i <= n; i++){
            dp1[i] = dp1[i - 1] + a[i];
            if(dp2[i - 1] != -1) dp1[i] = min(dp1[i], dp2[i - 1] + a[i]);
            if(i - k >= 0){
                dp2[i] = dp1[i - k] + a[i];
                if(dp2[i - k] != -1) dp2[i] = min(dp2[i], dp2[i - k] + a[i]);
            }
            if(dp1[i] <= p || (dp2[i] != -1 && dp2[i] <= p)) ans = i;
        }
        cout << ans << "\n";

    }

    return 0;
}
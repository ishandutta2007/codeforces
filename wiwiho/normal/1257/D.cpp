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

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int m;
        cin >> m;
        vector<pii> h(m);
        for(int i = 0; i < m; i++){
            cin >> h[i].S >> h[i].F;
        }
        gsort(h);

        vector<int> pwr(n + 1);
        int pnt = 0;
        int mx = 0;
        for(int i = n; i > 0; i--){
            while(pnt < m && h[pnt].F >= i){
                mx = max(mx, h[pnt].S);
                pnt++;
            }
            pwr[i] = mx;
        }

        int ans = 1;
        int start = 0;
        mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, a[i]);
            if(pwr[1] < mx){
                ans = -1;
                break;
            }
            if(pwr[i - start + 1] < mx){
                start = i;
                mx = a[i];
                ans++;
            }
        }

        cout << ans << "\n";

    }

    return 0;
}
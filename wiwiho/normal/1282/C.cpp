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

    int m;
    cin >> m;

    while(m--){

        int n;
        ll T, a, b;
        cin >> n >> T >> a >> b;

        int ez = 0, hd = 0;
        int sa = 0, sb = 0;
        vector<pii > p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i].S;
            if(p[i].S) sb++;
            else sa++;
        }
        for(int i = 0; i < n; i++) cin >> p[i].F;

        p.eb(mp(0, -1));
        p.eb(mp(T + 1, -1));
        lsort(p);

        int ans = 0;
        for(int i = 0; i <= n; i++){

            if(p[i].S == 1) hd++;
            else if(p[i].S == 0) ez++;
            if(p[i + 1].F == p[i].F) continue;

            int sez = ez, shd = hd;
            //cerr << i << " " << sez << " " << shd << "\n";
            if(sez * a + shd * b >= p[i + 1].F) continue;
            ll tm = sez * a + shd * b;

            int ta = sa - sez, tb = sb - shd;
            for(int j = 20; j >= 0; j--){
                if(ta >= (1 << j) && (1 << j) * a + tm < p[i + 1].F)
                    ta -= (1 << j), sez += (1 << j), tm += (1 << j) * a;
            }
            for(int j = 20; j >= 0; j--){
                if(tb >= (1 << j) && (1 << j) * b + tm < p[i + 1].F)
                    tb -= (1 << j), shd += (1 << j), tm += (1 << j) * b;
            }
            //cerr << i << " " << p[i].F << " " << sez << " " << shd << "\n";

            ans = max(ans, sez + shd);

        }

        cout << ans << "\n";
    }


    return 0;
}
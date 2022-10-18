//pC Gauntlet 100/100 (unofficial)

//#define NDEBUG

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
const ll MAX = 1000000000;

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int b, p, f;
        cin >> b >> p >> f;
        int h, c;
        cin >> h >> c;

        int ans = 0;
        if(h >= c){
            int t = min(b / 2, p);
            b -= t * 2;
            ans += t * h;
            int t2 = min(b / 2, f);
            ans += t2 * c;
        }
        else{
            int t = min(b / 2, f);
            b -= t * 2;
            ans += t * c;
            int t2 = min(b / 2, p);
            ans += t2 * h;
        }

        cout << ans << "\n";

    }
 
    return 0;
}
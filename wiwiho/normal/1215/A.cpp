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
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int a1, a2;
    cin >> a1 >> a2;

    int k1, k2;
    cin >> k1 >> k2;

    int n;
    cin >> n;

    int mn = 100000, mx = 0;
    for(int i = 0; i <= a1; i++){
        for(int j = 0; j <= a2; j++){

            if(i * k1 + j * k2 > n) continue;
            int r1 = a1 - i;
            int r2 = a2 - j;
            int r = r1 * (k1 - 1) + r2 * (k2 - 1);
            if(i * k1 + j * k2 + r < n) continue;
            mn = min(mn, i + j);
            mx = max(mx, i + j);

        }
    }

    cout << mn << " " << mx << "\n";
    


    return 0;
}
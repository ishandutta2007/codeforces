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

int popcnt(ll a){
    int ans = 0;
    for(int i = 0; (1LL << i) <= a; i++){
        if((1LL << i) & a) ans++;
    }
    return ans;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    
    while(n--){

        ll l, r;
        cin >> l >> r;

        ll ans = 0;

        ll high = 0;
        for(;(1LL << high) <= r; high++);

        ll now = 0;
        for(ll i = high; i >= 0; i--){
            if(!((1LL << i) & r)) continue;
            now += (1LL << i) - 1;
            if(now >= l && popcnt(ans) < popcnt(now)) ans = now;
            now++;
            if(now >= l && popcnt(ans) < popcnt(now)) ans = now;
        }

        cout << ans << "\n";

    }

    return 0;
}
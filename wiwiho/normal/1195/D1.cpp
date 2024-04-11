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
#define fr front()
#define po pop()
#define ba back()
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

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;
const ll MAX = 1000000001;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    ll ans = 0;
    for(int i = 0; i < n; i++){

        ll t;
        cin >> t;
        ll temp = 0;
        ll ten = 1;
        while(t > 0){
            temp += (t % 10) * ten;
            ten *= 100;
            t /= 10;
        }
        //cerr << temp << "\n";

        ans += ((temp % MOD) * n) % MOD;
        ans %= MOD;
        ans += (((temp % MOD) * 10) * n) % MOD;
        ans %= MOD;

    }

    cout << ans << "\n";

    return 0;
}
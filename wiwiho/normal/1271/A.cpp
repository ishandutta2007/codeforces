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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    if(e > f){

        ll ans = 0;
        ll t = min(a, d);
        ans += t * e;
        d -= t;
        t = min({d, b, c});
        ans += t * f;
        cout << ans << "\n";
    }
    else{
        ll ans = 0;
        ll t = min({d, b, c});
        ans += t * f;
        d -= t;
        t = min(a, d);
        ans += t * e;
        cout << ans << "\n";
    }

    return 0;
}
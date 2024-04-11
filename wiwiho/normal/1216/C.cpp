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

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    int x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    x3 = max(x1, min(x3, x2));
    x4 = max(x1, min(x4, x2));
    x5 = max(x1, min(x5, x2));
    x6 = max(x1, min(x6, x2));
    y3 = max(y1, min(y3, y2));
    y4 = max(y1, min(y4, y2));
    y5 = max(y1, min(y5, y2));
    y6 = max(y1, min(y6, y2));

    ll a = (ll)(x2 - x1) * (y2 - y1);
    ll b = (ll)(x4 - x3) * (y4 - y3);
    ll c = (ll)(x6 - x5) * (y6 - y5);

    x5 = max(x3, min(x5, x4));
    x6 = max(x3, min(x6, x4));
    y5 = max(y3, min(y5, y4));
    y6 = max(y3, min(y6, y4));
    ll d = (ll)(x6 - x5) * (y6 - y5);
    a = a - b - c + d;

    //cerr << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
    //cerr << x5 << " " << y5 << " " << x6 << " " << y6 << "\n";
    if(a > 0) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
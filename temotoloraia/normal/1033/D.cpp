#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo
using namespace std;
const ll N = 505, M = 2e18, MM = 15e7, MOD = 998244353;
ll n, a[N];
ll ans = 1;
vector < ll > P;
map < ll, ll > MY, MP;
ll F[N];
int main()
{
    #ifdef temo
    freopen  ("in.in", "r", stdin);
    freopen  ("out.out", "w", stdout);
    #endif // temo
    cin>>n;
    for (ll i = 1; i <= n; i++){
        cin>>a[i];
        ll x = cbrtl (a[i]);
        if (x * x * x == a[i]){
            P.pb (x);
            continue;
        }
        x = sqrtl(a[i]);
        if (a[i] != x * x)
            continue;
        ll y = sqrtl(x);
        if (x == y * y)
            x = y;
        if (MY[x] == 0){
            P.pb (x);
            MY[x] = 1;
        }
    }
    for (ll i = 0; i < P.size(); i++){
        ll x = 1;
        for (ll j = 1; j <= n; j++)
            while (a[j] % P[i] == 0){
                a[j] /= P[i];
                x++;
                F[j] = 1;
            }
        ans = ans * x % MOD;
    }
    P.clear();
    for (ll i = 1; i <= n; i++)
        if (a[i] > 1)
        for (ll j = i + 1; j <= n; j++){
            ll z = __gcd (a[i], a[j]);
            ll x = a[i], y = a[j];
            if (z == 1 || x == y)
                continue;
            if (MY[z] == 0){
                P.pb (z);
                MY[z] = 1;
            }
            if (MY[x / z] == 0 && x > z){
                P.pb (x / z);
                MY[x / z] = 1;
            }
            if (MY[y / z] == 0 && y > z){
                P.pb (y / z);
                MY[y / z] = 1;
            }
        }
    for (ll i = 0; i < P.size(); i++){
        ll x = 1;
        for (ll j = 1; j <= n; j++)
            while (a[j] % P[i] == 0){
                a[j] /= P[i];
                x++;
                F[j] = 1;
            }
        ans = ans * x % MOD;
    }
    P.clear();
    MP[1] = 1;
    for (ll i = 1; i <= n; i++)
        if (MP[a[i]] == 0){
            ll t = 1;
            MP[a[i]] = 1;
            for (ll j = 1; j <= n; j++)
                if (a[j] == a[i])
                    t++;
            for (ll k = 0; k < 2 - F[i]; k++)
                ans = ans * t % MOD;
        }
    cout<<ans<<endl;
    return 0;
}
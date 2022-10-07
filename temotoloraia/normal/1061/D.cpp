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
const ll N = 1e5 + 7, MOD = 1e9 + 7;
ll n, x, y, ans;
ll l[N], r[N];
pair < ll, ll > P[N];
multiset < ll > S;
multiset < ll >::iterator I;
int main()
{
    cin>>n>>x>>y;
    for (ll i = 1; i <= n; i++)
        cin>>P[i].F>>P[i].S;
    sort (P + 1, P + n + 1);
    for (ll i = 1; i <= n; i++){
        l[i] = P[i].F;
        r[i] = P[i].S;
    }
    for (ll i = 1; i <= n; i++){
        I = S.lower_bound (l[i]);
        if (I != S.begin()){
            I--;
            if (y * (l[i] - (*I)) < x){
                ans = (ans + y * (r[i] - (*I))) % MOD;
                S.erase (I);
                S.insert(r[i]);
                continue;
            }
        }
        ans = (ans + x + (r[i] - l[i]) * y) % MOD;
        S.insert (r[i]);
    }
    cout<<ans<<endl;
    return 0;
}
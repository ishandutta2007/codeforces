#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 60;
int a[MAXN + 5], b[MAXN + 5];
ll ans;
int main()
{
    ll l, r;
    cin>>l>>r;
    for (int i = 60; i >= 1; i--){
        a[i] = l % 2;
        l /= 2;
    }
    for (int i = 60; i >= 1; i--){
        b[i] = r % 2;
        r /= 2;
    }
    ll x = 1;
    for (int i = 0; i < 59; i++)
        x *= 2;
    bool ok = 0;
    for (int i = 1; i <= 60; i++){
        if (a[i] < b[i])
            ok = 1;
        if (ok)
            ans += x;
        x /= 2;
    }
    cout<<ans<<endl;
    return 0;
}
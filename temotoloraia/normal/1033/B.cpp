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
const int N = 1e5 + 5;
int main()
{
    #ifdef temo
    freopen  ("in.in", "r", stdin);
    freopen  ("out.out", "w", stdout);
    #endif // temo
    int t;
    cin>>t;
    while (t--){
        ll a, b;
        cin>>a>>b;
        if (a - b > 1){
            cout<<"NO\n";
            continue;
        }
        a+=b;
        bool ok = 0;
        for (ll i = 2; i * i <= a; i++)
            if (a % i == 0)
                ok = 1;
        if (ok)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
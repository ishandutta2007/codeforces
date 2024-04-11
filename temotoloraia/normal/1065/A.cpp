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
int main()
{
    #ifdef temo
    freopen  ("in.in", "r", stdin);
    freopen  ("out.out", "w", stdout);
    #endif temo
    ll t;
    cin>>t;
    while (t--){
        ll s, a, b, c;
        cin>>s>>a>>b>>c;
        ll x =  s / (a * c);
        cout<<s / (a * c) * (a + b) + s % (a * c) / c<<endl;
    }
    return 0;
}
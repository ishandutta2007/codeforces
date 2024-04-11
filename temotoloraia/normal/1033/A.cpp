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
    int n;
    cin>>n;
    int a,b,c,d,x,y;
    cin>>c>>d>>a>>b>>x>>y;
    a -= c;
    b -= d;
    x -= c;
    y -= d;
    if (a * x < 0 || b * y < 0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    return 0;
}
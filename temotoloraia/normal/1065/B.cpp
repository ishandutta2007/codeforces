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
    ll n, m;
    cin>>n>>m;
    if (m == 0){
        cout<<n<<" "<<n<<endl;
        return 0;
    }
    if (n % 2 == 0)
        cout<<max (0ll, n - m * 2)<<" ";
    else {
        if (m * 2 > n)
            cout<<"0 ";
        else
            cout<<1 + max (0ll, n - 1 - m * 2)<<" ";
    }
    ll t = 1;
    while (t * (t - 1) / 2 < m)
        t++;
    cout<<n - t<<endl;
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

using namespace std;

const int N = 1e5 + 5;

int n;
ll x[N], y[N];
ll a[N], b[N];
ll X, Y;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>x[i]>>y[i];
        X += x[i];
        Y += y[i];
    }
    for (int i = 1; i <= n; i++){
        cin>>x[i]>>y[i];
        X += x[i];
        Y += y[i];
    }
    cout<<X / n<<" "<<Y / n<<endl;
    return 0;
}
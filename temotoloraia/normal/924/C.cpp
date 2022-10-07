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
using namespace std;
const int N = 100005;
int n, a[N], b[N];
ll ans;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = n; i >= 1; i--)
        b[i] = max (b[i + 1] - 1, a[i] + 1);
    for (int i = 1; i <= n; i++)
        b[i] = max (b[i], b[i - 1]);
    for (int i = 1; i <= n; i++)
        ans += b[i]-a[i]-1;
    cout<<ans<<endl;
    return 0;
}
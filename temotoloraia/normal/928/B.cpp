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
const int N = 1e5 + 7;
int n, k, a[N];
int l[N], r[N];
int dp[N];
int main()
{
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++){
        l[i] = max (i - k, 1);
        r[i] = min (i + k, n);
    }
    for (int i = 1; i <= n; i++){
        if (a[i] == 0){dp[i] = r[i] - l[i] + 1;continue;}
        dp[i] = dp[a[i]] + r[i] - l[i] + 1;
        if (r[a[i]] >= l[i])
            dp[i] -= r[a[i]] - l[i] + 1;
    }
    for (int i = 1; i <= n; i++)
        cout<<dp[i]<<" ";
    return 0;
}
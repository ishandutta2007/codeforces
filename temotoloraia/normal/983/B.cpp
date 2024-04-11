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
const int N = 5005;
int n;
int a[N], dp[N][N];
main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++)
        dp[i][i] = a[i];
    for (int l = 1; l < n; l++)
        for (int i = 1; i + l <= n; i++)
            dp[i][i+l] = (dp[i+1][i+l] ^ dp[i][i+l-1]);
    for (int l = 1; l < n; l++)
        for (int i = 1; i + l <= n; i++)
            dp[i][i+l] = max (dp[i][i+l],max (dp[i+1][i+l],dp[i][i+l-1]));
    int Q;
    cin>>Q;
    while (Q--){
        int l, r;
        scanf ("%d%d",&l,&r);
        printf ("%d\n",dp[l][r]);
    }
    return 0;
}
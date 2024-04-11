#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
LL n, b[3];
LL a[100005];
LL dp[100005];
int main()
{
    cin>>n;
    for (int i = 0; i < 3; i++)
        cin>>b[i];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    for (int i = 0; i < 3; i++){
        dp[0] += b[i] * a[0];
        for (int j = 1; j < n; j++)
            dp[j] = max (dp[j - 1], dp[j] + b[i] * a[j]);
    }
    cout<<dp[n - 1]<<endl;
    return 0;
}
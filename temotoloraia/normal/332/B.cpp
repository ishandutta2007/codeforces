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
const int MAXN = 200000;
int n, k;
ll a[MAXN + 5];
ll dp[MAXN + 5];
int ind[MAXN + 5];
ll ans;
int x, y;
int main()
{
    cin>>n>>k;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] += a[i - 1];
    }
    for (int i = k; i <= n; i++){
        dp[i] = dp[i - 1];
        ind[i] = ind[i - 1];
        if (dp[i] < a[i] - a[i - k]){
            dp[i] = a[i] - a[i - k];
            ind[i] = i - k + 1;
        }
        if (i >= k * 2 && ans < a[i] - a[i - k] + dp[i - k]){
            ans = a[i] - a[i - k] + dp[i - k];
            x = ind[i - k];
            y = i - k + 1;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
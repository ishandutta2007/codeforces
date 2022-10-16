#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b,c) max(a,max(b,c))
 
int n,a,b,c,dp[4001];
 
int f(int x)
{
    if (x == 0) return 0;
    if (x < 0 || (x > 0 && x < a && x < b && x < c)) return INT_MIN;
    if (!dp[x]) dp[x] = MAX(f(x-a),f(x-b),f(x-c)) + 1;
    return dp[x];
}
 
int main()
{
    cin >> n >> a >> b >> c;
    memset(dp,0,sizeof(dp));
    cout << f(n) << endl;
}
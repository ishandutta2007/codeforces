
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
#define int ll
const int mod = 1e9+7;
int dp[1005][1005][2];
int dfs(int a,int b,int f)
{
    if(dp[a][b][f] != -1) return dp[a][b][f];
    if(a==0) return (b+f)/2;
    if(a==b) return dp[a][b][f] = (dfs(a-1,b,1-f) + f) % mod;
    int ret = 0;
    if(f) ret += dfs(a-1,b,0) + 1;
    else ret += dfs(a-1,b,1);
    ret += dfs(a,b-1,1);
    ret %= mod;
    return dp[a][b][f] = ret;
}
int32_t main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout << dfs(n,n,1) << endl;
}
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int dp[505][505],dp2[505][505];
int a[505];
int f(int l,int r)
{
    if(l == r) return a[l];
    if(dp[l][r] != -1) return dp[l][r];
    int ret = 0;
    for(int k=l;k<r;++k)
    {
        int a = f(l,k), b = f(k+1, r);
        if(a && b && a == b) { ret = a + 1; break; }
    }
    return dp[l][r] = ret;
}
int g(int l,int r)
{
    if(f(l,r)) return 1;
    if(dp2[l][r] != -1) return dp2[l][r];
    int ret = 1e9;
    for(int k=l;k<r;++k)
    {
        ret = min(ret, g(l,k) + g(k+1, r));
        
    }
    return dp2[l][r] = ret;
}
int main()
{
    int n;
    cin >> n;
    ii cin >> a[i];
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp));
    cout << g(1,n) << endl;
}
// x x x+1 x+2 ...
//
// 4 2 2 3
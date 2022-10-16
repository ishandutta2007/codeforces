#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

db DP[2][905];

int main()
{
    #define dp(i,j) DP[(i)&1][j]

    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) rep(t,1,900)
    {
        dp(i,t) = (t/2.0 + (db)t/(t+1))/k + dp(i-1,t)*(1-1.0/(k*(t+1))) + dp(i-1,t+1)/(k*(t+1));
    }
    printf("%.15f\n",dp(n,1)*k);
    return 0;
}
#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 5000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];
bool dp[maxn+5];

int lg(int n)
{
    return n==1?0:1+lg(n/2);
}

int main()
{
    scanf("%s",s+1); int n=strlen(s+1),k=lg(n);
    dp[0]=1;
    rep(i,1,n-(1<<k)+1)
    {
        rep(msk,0,(1<<k)-1) if(dp[msk]) rep(b,0,k-1) dp[msk|(1<<b)]=1;
        char c='z';
        rep(msk,0,(1<<k)-1) if(dp[msk]) c=min(c,s[i+msk]);
        rep(msk,0,(1<<k)-1) if(s[i+msk]!=c) dp[msk]=0;
        putchar(c);
    }
    puts("");
    return 0;
}
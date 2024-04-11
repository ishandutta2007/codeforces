#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 50
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5][25];
db dp[1<<20];
ll mask[1<<20];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%s",s[i]);
    int m=strlen(s[1]),B=(1<<m);
    rep(i,1,n) rep(j,i+1,n)
    {
        int st=0;
        rep(k,0,m-1) st|=(s[i][k]==s[j][k])<<k;
        mask[st]|=(1ll<<i)|(1ll<<j);
    }
    per(st,0,B-1) rep(i,0,m-1) if(st&(1<<i)) mask[st^(1<<i)]|=mask[st];
    db ans=0;
    dp[0]=1;
    rep(st,0,B-1) 
    {
        int N=m-__builtin_popcount(st);
        db p=dp[st]/(db)N;
        rep(i,0,m-1) if((st&(1<<i))==0) 
        {
            dp[st|(1<<i)]+=p;
            ans+=p*__builtin_popcountll(mask[st]-mask[st|(1<<i)])*(m-N+1);
        }
        //printf("? %d: %.6f\n",st,dp[st]);
    }
    //rep(st,0,B-1) printf("%d: %lld\n",st,mask[st]);
    printf("%.15f\n",ans/n);
    return 0;
}
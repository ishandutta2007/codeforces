#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 1000
#define mod 1000000007
using namespace std;
typedef long long ll;
int a[maxn+5],res[30],tmp,minans[maxn+5],maxl;
ll f[maxn+5];
char s[maxn+5];
int main()
{
    int i,j,n;
    scanf("%d",&n);
    scanf("%s",s+1);
    rep(i,1,n) a[i]=s[i]-'a'+1;
    rep(i,1,26) scanf("%d",&res[i]);
    memset(minans,127,sizeof minans);
    minans[0]=0;
    f[0]=1;
    rep(i,1,n)
    {
        tmp=0x7fffffff;
        rep(j,1,i)
        {
            tmp=min(tmp,res[a[i-j+1]]);
            if(tmp<j) break;
            minans[i]=min(minans[i-j]+1,minans[i]);
            f[i]=(f[i]+f[i-j])%mod;
        }
        maxl=max(maxl,j-1);
    }
    printf("%I64d\n%d\n%d\n",f[n],maxl,minans[n]);
    return 0;
}
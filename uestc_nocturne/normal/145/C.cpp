/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int P=1000000007;
int nu[120];
bool check(int x)
{
    int t=0;
    while(x)
    {
        nu[t++]=x%10;
        x/=10;
    }
    for(int i=0;i<t;i++)
    if(nu[i]!=4&&nu[i]!=7)
    return false;
    return true;
}
int Ln,L[1200];
const int V=100100;
LL Pow(LL x,int y)
{
    LL ret=1;
    LL te=x;
    while(y)
    {
        if(y&1)ret=(ret*te)%P;
        te=te*te%P;y/=2;
    }
    return ret;
}
LL dp[2][1200],C[V];
int a[V];
int n,K,i,j,fl,te,S;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);Ln=0;
        S=n;
        for(i=0;i<n;i++)
        {
            if(i!=0&&a[i]==a[i-1])continue;
            if(check(a[i]))
            {
                j=i;
                while(j<n&&a[j]==a[i])j++;
                L[Ln++]=j-i;
                S-=(j-i);
            }
        }
        memset(C,0,sizeof(C));
        C[0]=1;
        for(i=1;i<=S;i++)
        C[i]=C[i-1]*(S-i+1)%P*Pow((LL)i,P-2)%P;
        memset(dp,0,sizeof(dp));
        fl=0;dp[0][0]=1;
        for(i=0;i<Ln;i++)
        {
            te=1-fl;
            for(j=0;j<=Ln;j++)
            {
                dp[te][j]=0;
                if(j!=0)dp[te][j]+=dp[fl][j-1]*L[i]%P;
                dp[te][j]+=dp[fl][j];
                dp[te][j]%=P;
            }
            fl=te;
        }
        LL ans=0;
        for(i=0;i<=K&&i<=Ln;i++)
        {
            ans+=dp[fl][i]*C[K-i]%P;
            ans%=P;
        }
        cout<<ans<<endl;
    }
}
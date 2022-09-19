#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
const int maxn=4000;
int ans[maxn][maxn];
int fact[maxn];int invf[maxn];
int f(int x,int y)
{
    if(y<0 || x<0 || y>x) return 0;
    int res=fact[x];res*=invf[x-y];return (res%p);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;} for(int i=0;i<maxn;++i) invf[i]=inv(fact[i]);
    int n,m,k;cin>>n>>m>>k;bool ok1[n];for(int i=0;i<n;++i) ok1[i]=1; bool ok2[m];for(int i=0;i<m;++i) ok2[i]=1;
    int a[k][4];for(int i=0;i<k;++i) {for(int j=0;j<4;++j) {cin>>a[i][j];--a[i][j];if(j%2==0) ok1[a[i][j]]=false; else ok2[a[i][j]]=false;}}
    ans[0][0]=1;int cnt1=0,cnt2=0;for(int i=0;i<n;++i) cnt1+=ok1[i]; for(int i=0;i<m;++i) cnt2+=ok2[i];
    for(int i=0;i<n;++i)
    {
        if(ok1[i] && i>0 && ok1[i-1])
        {
            ans[i+1][0]=1;
            for(int j=1;j<=n;++j) {ans[i+1][j]=ans[i][j]+ans[i-1][j-1];if(ans[i+1][j]>=p) ans[i+1][j]-=p;}
            continue;
        }
        else
        {
            for(int j=0;j<=n;++j) {ans[i+1][j]=ans[i][j];}
            continue;
        }
    }
    int res1[n+1]={0};for(int i=0;i<=n;++i) res1[i]=ans[n][i];
    for(int i=0;i<=m;++i) for(int j=0;j<=m;++j) ans[i][j]=0;
    ans[0][0]=1;
    for(int i=0;i<m;++i)
    {
        if(ok2[i] && i>0 && ok2[i-1])
        {
            ans[i+1][0]=1;
            for(int j=1;j<=m;++j) {ans[i+1][j]=ans[i][j]+ans[i-1][j-1];if(ans[i+1][j]>=p) ans[i+1][j]-=p;}
            continue;
        }
        else
        {
            for(int j=0;j<=m;++j) {ans[i+1][j]=ans[i][j];}
            continue;
        }
    }
    int res2[m+1]={0};for(int i=0;i<=m;++i) res2[i]=ans[m][i];
    int answ=0;
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            int o=res1[i]*res2[j];o%=p;
            if(!o) continue;
            o*=f(cnt1-2*i,j);o%=p;o*=f(cnt2-2*j,i);o%=p;
            answ+=o;answ%=p;
        }
    }
    cout<<(answ%p+p)%p;
    return 0;
}
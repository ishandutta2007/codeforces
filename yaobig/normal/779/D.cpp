#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 200000
#define pb push_back
using namespace std;
char t[maxn+5],p[maxn+5];
int a[maxn+5],n;
bool mark[maxn+5];
bool check(int k)
{
    memset(mark,0,sizeof mark);
    int i,pt=1,pp=1;
    rep(i,1,k) mark[a[i]]=1;
    while(t[pt]!=0 && p[pp]!=0)
    {
        if(t[pt]==p[pp] && mark[pt]==0) pp++;
        pt++;
    }
    if(p[pp]==0) return 1;
    return 0;
}
int lb(int l,int r)
{
    r++;
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(check(mid)<1) r=mid;
        else l=mid+1;
    }
    return r-1;
}
int main()
{
    int i,ans;
    scanf("%s%s",t+1,p+1);
    n=strlen(t+1);
    rep(i,1,n) scanf("%d",&a[i]);
    ans=lb(0,n);
    printf("%d\n",ans);
    return 0;
}
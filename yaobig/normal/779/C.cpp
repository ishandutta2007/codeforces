#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 200000
#define pb push_back
using namespace std;
int a[maxn+5],b[maxn+5],c[maxn+5],n,k,ans;
struct node
{
    int a,b,c;
}data[maxn+5];
bool cmp(node x,node y)
{
    return x.c<y.c;
}
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&data[i].a);
    rep(i,1,n) scanf("%d",&data[i].b);
    rep(i,1,n) data[i].c=data[i].a-data[i].b;
    sort(data+1,data+n+1,cmp);
    rep(i,1,k) ans+=data[i].a;
    rep(i,k+1,n) ans+=(data[i].c<0)?data[i].a:data[i].b;
    printf("%d\n",ans);
    return 0;
}
#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define per(i,a,n) for(i=n;i>=a;i--)
#define maxn 1000000
#define pb push_back
using namespace std;
int n,m,k;
int val[maxn+5],c[maxn+5];
struct node
{
    int date,num;
    node(int a=0,int b=0):date(a),num(b){}
}a[maxn+5],b[maxn+5];
bool cmp(node x,node y)
{
    return x.date<y.date;
}
bool check(int x)
{
    int ptr1=1,ptr2=m-x+1,cnt=0,i;
    while(ptr1<=n || ptr2<=m)
    {
        cnt++;
        if(ptr1>n) c[cnt]=b[ptr2++].date;
        else if(ptr2>m) c[cnt]=a[ptr1++].date;
        else
        {
            if(a[ptr1].date<b[ptr2].date) c[cnt]=a[ptr1++].date;
            else c[cnt]=b[ptr2++].date;
        }
    }
    rep(i,0,maxn*2+1)
    {
        if(i*k+1>cnt) break;
        if(c[i*k+1]<i) return 0;
    }
    return 1;
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
    int i,v,cnt=0;
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n) scanf("%d",&v),a[i]=node(v,0);
    rep(i,1,m) scanf("%d",&v),b[i]=node(v,i);
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+m+1,cmp);
    int t=lb(0,m);
    printf("%d\n",t);
    if(t==0) printf("\n");
    else
    {
        per(i,m-t+1,m) printf("%d%s",b[i].num,i==m-t+1?"\n":" ");
    }
    return 0;
}
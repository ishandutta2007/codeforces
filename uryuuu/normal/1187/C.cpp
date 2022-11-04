#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
//#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

int a[1050],v[1005];
struct node
{
    int l,r;
}x[1005],y[1005],b[1005];
bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}


int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    mm(a);
    int xnt=0,ynt=0;
    int d,l,r;
    for(int i=0;i<m;i++)
    {
        cin>>d>>l>>r;
        if(d==1)
        {
            x[xnt].l=l;
            x[xnt++].r=r;
        }
        else
        {
            y[ynt].l=l;
            y[ynt++].r=r;
        }
    }
    if(xnt==0)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<1000000-i<<' ';
        cout<<endl;
        return 0;
    }
    int s=100000000;
    sort(x,x+xnt,cmp);
    int cnt=1;
    b[1]=x[0];
    for(int i=1;i<xnt;i++)
    {
//        cout<<b[cnt].l<<' '<<b[cnt].r<<endl;
        if(b[cnt].r>=x[i].l)
        {
            b[cnt].r=max(x[i].r,b[cnt].r);
        }
        else
        {
            b[++cnt]=x[i];
        }
    }
    
    for(int i=1;i<=cnt;i++,s-=4000)
    {
//        cout<<b[i].l<<' '<<b[i].r<<endl;
        for(int j=b[i].l;j<=b[i].r;j++)
            a[j]=s;
    }
    
    if(a[n]==0)
        a[n]=1;
    
    for(int i=n;i>=1;i--)
    {
        if(a[i]==0)
        {
            a[i]=a[i+1]+1;
        }
    }
    for(int i=0;i<ynt;i++)
    {
        int f=0;
        for(int j=y[i].l;j<y[i].r;j++)
        {
            if(a[j]>a[j+1])
                f=1;
        }
        if(f==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
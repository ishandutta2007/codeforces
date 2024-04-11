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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;



struct node
{
    int l,r;
}a[maxn];

int L[maxn],R[maxn];

void upd1(int x,int y)
{
    while(x<maxn)
    {
        L[x]+=y;
        x+=lb(x);
    }
}

int qry1(int x)
{
    int sum=0;
    while(x)
    {
        sum+=L[x];
        x-=lb(x);
    }
    return sum;
}

void upd2(int x,int y)
{
    while(x<maxn)
    {
        R[x]+=y;
        x+=lb(x);
    }
}

int qry2(int x)
{
    int sum=0;
    while(x)
    {
        sum+=R[x];
        x-=lb(x);
    }
    return sum;
}


int b[maxn];
bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        rep(i,1,n)
        {
            cin>>a[i].l>>a[i].r;
            b[++cnt]=a[i].l;
            b[++cnt]=a[i].r;
        }
        sort(b+1,b+cnt+1);
        int m=unique(b+1,b+cnt+1)-b-1;
        sort(a+1,a+n+1,cmp);
        for(int i=0;i<=m+5;i++)
        {
            L[i]=0;
            R[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            a[i].l=lower_bound(b+1,b+m+1,a[i].l)-b;
            a[i].r=lower_bound(b+1,b+m+1,a[i].r)-b;
            upd1(a[i].l,1);
            upd2(a[i].r,1);
        }
        int ans=n;
        int sum;
        for(int i=1;i<=n;i++)
        {
//            cout<<a[i].l<<' '<<a[i].r<<' '<<qry1(a[i].r)<<' '<<qry2(a[i].l-1)<<endl;
            sum=(n-qry1(a[i].r)+qry2(a[i].l-1));
//            cout<<sum<<' ';
            ans=min(ans,sum);
        }
        cout<<ans<<endl;
        
    }
    
    
    return 0;
}
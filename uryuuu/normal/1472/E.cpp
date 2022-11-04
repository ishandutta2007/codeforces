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
    int x,y,id;
}a[maxn];

int pos[maxn];
int h[maxn];
int X[maxn];
int ans[maxn];

bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
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
        int x,y;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            a[++cnt].id=i;
            a[cnt].x=x;
            a[cnt].y=y;
            X[cnt]=x;
            
            a[++cnt].id=i;
            a[cnt].x=y;
            a[cnt].y=x;
            X[cnt]=y;
        }
        sort(X+1,X+cnt+1);
        int m=unique(X+1,X+cnt+1)-X-1;
        for(int i=1;i<=cnt;i++)
        {
            a[i].x=lower_bound(X+1,X+m+1,a[i].x)-X;
        }
        sort(a+1,a+cnt+1,cmp);
        int mn=1e9+5;
        int id=0;
        for(int i=1;i<=cnt;i++)
        {
            if(i>1&&a[i].x==a[i-1].x)
                continue;
            if(a[i].y<mn)
            {
                mn=a[i].y;
                id=a[i].id;
            }
            pos[a[i].x]=id;
            h[a[i].x]=mn;
        }
        for(int i=1;i<=n;i++)
            ans[i]=-1;
        for(int i=1;i<=cnt;i++)
        {
            if(a[i].x==1)
                continue;
            if(h[a[i].x-1]<a[i].y&&pos[a[i].x-1]!=a[i].id)
                ans[a[i].id]=pos[a[i].x-1];
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
        
        
        
    }
    
    return 0;
}
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
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[maxn],b[maxn],vis[maxn];
int n;

int qry(int x)
{
    int ans=n+2;
    if(x==0)
        return 0;
    while(x)
    {
        ans=min(b[x],ans);
        x-=lb(x);
    }
    return ans;
}

void add(int x,int val)
{
    while(x<maxn)
    {
        b[x]=min(b[x],val);
        x+=lb(x);
    }
}

int pre[maxn],lst[maxn];

int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        lst[i]=n+2;
        b[i]=n+2;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(lst[a[i]]==n+2)
            pre[i]=0;
        else
            pre[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    int L;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1)
            vis[1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(lst[i]==n+2)
        {
            if(qry(i-1)>=1)
                vis[i]=1;
            add(i,0);
        }
        else
        {
//            cout<<i<<' '<<' '<<qry(i-1)<<' '<<lst[i]+1<<endl;
            if(qry(i-1)>=lst[i]+1)
                vis[i]=1;
            add(i,lst[i]);
        }
    }
    if(qry(n)>=1)
        vis[n+1]=1;
    
    for(int i=n;i>=1;i--)
    {
        L=pre[i]+1;
//        cout<<a[i]<<' '<<L<<' '<<qry(a[i]-1)<<endl;
//        cout<<i<<' '<<lst[i]<<endl;
        if(a[i]>1&&qry(a[i]-1)>=L)
            vis[a[i]]=1;
        add(a[i],pre[i]);
    }
    int mex=1;
    for(int i=1;i<=n+2;i++)
    {
        if(vis[i]==0)
        {
            mex=i;
            break;
        }
    }
    cout<<mex<<endl;
    
    return 0;
}
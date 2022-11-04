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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
//const ll Mod=1000000007;
using namespace std;
 
 
int d[maxn];
int c[maxn];
struct node
{
    int u, v;
}a[maxn];
int g[maxn];
 
int main()
{
    sync;
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        d[u]++;
        d[v]++;
        a[i].u=u;
        a[i].v=v;
    }
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1)
            c[cnt++]=i;
    }
    int pos=1;
    if(cnt>3)
    {
        for(int i=1;i<n;i++)
        {
            if(d[a[i].u]==1||d[a[i].v]==1)
            {
                g[i]=pos;
                pos++;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(g[i]==0)
            {
                g[i]=pos++;
            }
        }
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            g[i]=i;
        }
    }
    for(int i=1;i<n;i++)
        cout<<g[i]-1<<endl;
    return 0;
}
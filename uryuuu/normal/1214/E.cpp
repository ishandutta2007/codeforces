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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;
const ll p=998857459;


vector<int>g[maxn];

struct node
{
    int d,id;
}a[maxn];

int b[maxn];

bool cmp(node a,node b)
{
    return a.d>b.d;
}

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].d;
        a[i].id=i;
    }
    int len=n;
    
    sort(a+1,a+n+1,cmp);
    
    for(int i=1;i<=n;i++)
    {
        b[i]=2*a[i].id-1;
    }
    
    for(int i=2;i<=n;i++)
    {
        g[b[i-1]].push_back(b[i]);
    }
    
    int l,v,u;
    
    for(int i=1;i<=n;i++)
    {
        l=a[i].d;
        v=a[i].id*2;
        u=i+l-1;
        g[b[u]].push_back(v);
        if(u==len)
        {
            b[++len]=v;
        }
    }
    for(int i=1;i<=2*n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            cout<<i<<' '<<g[i][j]<<endl;
        }
    }
    
    
    
    return 0;
}
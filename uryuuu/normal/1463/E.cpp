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


vector<int>g[maxn];
int son[maxn];
int cnt;
int anc[maxn];
int ans[maxn];
int vis[maxn];
int pre[maxn];
int fa[maxn];
int rt;
int d[maxn];



int main()
{
    sync;
    int n;
    int m;
    cin>>n;
    cin>>m;
    int u,v;
    for(int i=1;i<=n;i++)
    {
        cin>>v;
        if(v==0)
            rt=i;
        pre[i]=v;
    }
    

    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        if(son[u]||fa[v])
        {
            cout<<0<<endl;
            return 0;
        }
        son[u]=v;
        fa[v]=u;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(fa[i])
            continue;
        u=i;
        while(u)
        {
            if(anc[pre[u]]!=i)
            {
                d[i]++;
                g[pre[u]].push_back(i);
            }
            anc[u]=i;
            u=son[u];
        }
    }
    
    cnt=0;
    queue<int>q;
    q.push(0);
    d[rt]--;
    if(d[rt]==0)
        q.push(rt);
    while(q.size())
    {
        u=q.front();
        q.pop();
        while(u)
        {
            ans[++cnt]=u;
            for(int v:g[u])
            {
                d[v]--;
                if(d[v]==0)
                    q.push(v);
            }
            u=son[u];
        }
    }
    
//    for(int i=1;i<=cnt;i++)
//        cout<<ans[i]<<' ';
//    cout<<endl;
//    
    if(cnt!=n)
    {
        cout<<0<<endl;
        return 0;
    }
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    
    
    return 0;
}
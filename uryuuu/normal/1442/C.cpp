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
//const ll Mod=1000000007;
const ll Mod = 998244353;

vector<int>g[maxn],fg[maxn];
int b[maxn];
ll dis[maxn];

struct node
{
    int id;
    bool operator<(const node& a)const
    {
        return dis[id]>dis[a.id];
    }
};

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        fg[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        dis[i]=9999999;
    }
    ll ans=998244352;
    dis[1]=0;
    priority_queue<node>q;
    node tmp;
    queue<int>Q;
    Q.push(1);
    int cnt=0;
    b[++cnt]=1;
    while(Q.size())
    {
        u=Q.front();
        Q.pop();
        for(int v:g[u])
        {
            if(dis[u]+1<dis[v])
            {
                dis[v]=dis[u]+1;
                Q.push(v);
                b[++cnt]=v;
            }
        }
    }
    
    node w;
    
    ans=min(ans,dis[n]);
    ll sum=0,fk=1ll;
    
    for(int i=0;i<20;i++)
    {
        fk=(1ll<<i);
        sum=sum+fk;
        while(q.size())
            q.pop();
        for(int i=1;i<=cnt;i++)
        {
            tmp.id=b[i];
            q.push(tmp);
        }
        cnt=0;
        if(i%2==0)
        {
            while(q.size())
            {
                w=q.top();
                q.pop();
                u=w.id;
                for(int v:fg[u])
                {
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        b[++cnt]=v;
                        tmp.id=v;
                        q.push(tmp);
                    }
                }
            }
            ans=min(ans,dis[n]+sum);
        }
        else
        {
            while(q.size())
            {
                w=q.top();
                q.pop();
                u=w.id;
                for(int v:g[u])
                {
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        b[++cnt]=v;
                        tmp.id=v;
                        q.push(tmp);
                    }
                }
            }
            ans=min(ans,dis[n]+sum);
        }
    }
    
    if(dis[n]<9999999)
    {
        cout<<ans<<endl;
        return 0;
    }
    for(int i=20;i<=n+5;i++)
    {
        if(dis[n]<9999999)
        {
            cout<<((dis[n]+sum%Mod)%Mod+Mod)%Mod<<endl;
            return 0;
        }
        fk=2ll*fk%Mod;
        sum=(1ll*sum+fk)%Mod;
        while(q.size())
            q.pop();
        for(int i=1;i<=cnt;i++)
        {
            tmp.id=b[i];
            q.push(tmp);
        }
        cnt=0;
        if(i%2==0)
        {
            while(q.size())
            {
                w=q.top();
                q.pop();
                u=w.id;
                for(int v:fg[u])
                {
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        b[++cnt]=v;
                        tmp.id=v;
                        q.push(tmp);
                    }
                }
            }
        }
        else
        {
            while(q.size())
            {
                w=q.top();
                q.pop();
                u=w.id;
                for(int v:g[u])
                {
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        b[++cnt]=v;
                        tmp.id=v;
                        q.push(tmp);
                    }
                }
            }
        }
    }
    
    
    return 0;
}
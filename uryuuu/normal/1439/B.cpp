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
int n,m,k;
int d[maxn],vis[maxn];
vector<int>h;

int main()
{
    sync;
    int t;
    cin>>t;
    int u,v;
    while(t--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            d[i]=0;
            vis[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            d[u]++;
            d[v]++;
        }
        if(1ll*k*(k-1)/2ll>m)
        {
//            cout<<k*(k-1)/2<<' '<<m<<endl;
            cout<<-1<<endl;
            continue;
        }
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
            sort(g[i].begin(),g[i].end());
            if(d[i]<k)
            {
                q.push(i);
                vis[i]=1;
            }
        }
        int f=0;
        int fl;
        while(q.size())
        {
            u=q.front();
            q.pop();
            vis[u]=2;
            if(d[u]==k-1)
            {
                h.clear();
                fl=0;
                h.push_back(u);
                for(int v:g[u])
                {
                    if(vis[v]<2)
                    {
                        h.push_back(v);
                    }
                }
                for(int u:h)
                {
                    for(int v:h)
                    {
                        if(u==v)
                            break;
                        if(binary_search(g[v].begin(),g[v].end(),u)==0)
                        {
//                            cout<<u<<' '<<v<<endl;
                            fl=1;
                        }
                    }
                    if(fl)
                        break;
                }
                if(fl==0)
                {
                    f=1;
                    break;
                }
            }
            for(int v:g[u])
            {
                d[v]--;
                if(vis[v])
                    continue;
                if(d[v]<k)
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        if(f)
        {
            cout<<2<<endl;
            for(int v:h)
                cout<<v<<' ';
            cout<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
                ans++;
        }
        if(ans)
        {
            cout<<1<<' '<<ans<<endl;
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==0)
                    cout<<i<<' ';
            }
            cout<<endl;
            continue;
        }
        cout<<-1<<endl;
        
    }
    return 0;
}
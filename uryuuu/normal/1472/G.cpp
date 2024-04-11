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

int d[maxn];
vector<int>g[maxn];
int a[maxn],ans[maxn];
bool cmp(int a,int b)
{
    return d[a]>d[b];
}

int main()
{
    sync;
    int t;
    cin>>t;
    int n,m,u,v;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            d[i]=-1;
            g[i].clear();
            a[i]=i;
        }
        while(m--)
        {
            cin>>u>>v;
            g[u].push_back(v);
        }
        queue<int>q;
        q.push(1);
        d[1]=0;
        while(q.size())
        {
            u=q.front();
            q.pop();
            for(int v:g[u])
            {
                if(d[v]==-1)
                {
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            ans[i]=d[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            u=a[i];
            for(int v:g[u])
            {
                if(d[v]<=d[u])
                    ans[u]=min(ans[u],d[v]);
                else
                    ans[u]=min(ans[u],ans[v]);
            }
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
        
    }
    
    
    return 0;
}
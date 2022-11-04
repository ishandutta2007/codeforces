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
//#include<unordered_map>
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
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

vector<int>g[maxn];
priority_queue<ll,vector<ll>,greater<ll> > q;
int vis[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(!q.empty()) q.pop();
    q.push(1);
    vis[1]=1;
    while(q.size())
    {
        u=q.top();
        cout<<u<<' ';
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
    cout<<endl;
    return 0;
}
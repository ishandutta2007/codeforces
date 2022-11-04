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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

vector<int>g[maxn];
int d[maxn];
int s,n,m;
ll w[maxn],cnt[maxn];
queue<int>q;


int main()
{
    sync;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    cin>>s;
    
    for(int i=1;i<=n;i++)
        if(d[i]==1&&i!=s)
            q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        d[u]=-1;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(d[v]<0)
                continue;
            d[v]--;
            cnt[v]=max(cnt[v],cnt[u]+w[u]);
            if(d[v]==1&&v!=s)
                q.push(v);
        }
        q.pop();
    }
    
//    cout<<cnt[2]<<endl;
    ll sum=0,da=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]<0)
            continue;
        sum+=w[i];
        da=max(da,cnt[i]);
    }
    cout<<sum+da<<endl;
    
    return 0;
}
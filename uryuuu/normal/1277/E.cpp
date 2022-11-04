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
using namespace std;
typedef pair<int,int> pii;
const int maxn=200005;
const ll Mod=1000000007;

ll n;
int m,a,b;
int x[maxn],y[maxn];
vector<int>g[maxn];
ll cnt1=0,cnt2=0;

void dfsa(int u)
{
    x[u]++;
    cnt1++;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=a&&x[v]==0)
            dfsa(v);
    }
    return;
}

void dfsb(int u)
{
    y[u]++;
    cnt2++;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=b&&y[v]==0)
            dfsb(v);
    }
    return;
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>a>>b;
        int u,v;
        for(int i=0;i<=n;i++)
        {
            x[i]=0;
            y[i]=0;
            g[i].clear();
        }
        while(m--)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cnt1=0;
        cnt2=0;
        dfsa(b);
        dfsb(a);
        cout<<1ll*(n-cnt1-1ll)*(n-cnt2-1ll)<<endl;
    }
    return 0;
}
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
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

vector<int>g[maxn],ans,d[maxn];
int dep[maxn];
stack<int>st;

int nd;
int dfs(int u)
{
    st.push(u);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(dep[v])
        {
            if(dep[u]-dep[v]+1>=nd)
            {
                while(st.top()!=v)
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                ans.push_back(st.top());
                return 1;
            }
        }
        else
        {
            dep[v]=dep[u]+1;
            if(dfs(v))
                return 1;
        }
    }
    st.pop();
    return 0;
}


int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    nd=ceil(sqrt(n));
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[1]=1;
    if(dfs(1))
    {
        cout<<2<<endl;
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
    else
    {
        cout<<1<<endl;
        for(int i=1;i<=n;i++)
        {
            d[dep[i]%(nd-1)].push_back(i);
        }
        for(int i=0;i<nd-1;i++)
        {
            if(d[i].size()>=nd)
            {
                for(int j=0;j<nd;j++)
                    cout<<d[i][j]<<' ';
                cout<<endl;
                return 0;
            }
        }
    }
    return 0;
}
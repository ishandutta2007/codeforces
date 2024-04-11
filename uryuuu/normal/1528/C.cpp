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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1000005;
//const ll Mod=1000000007;
const ll Mod=998244353;


vector<int>ag[maxn],bg[maxn];
int dfn[maxn],ed[maxn];
int tot;
int dp[maxn];
int pos[maxn*2];

void dfsb(int u)
{
    dfn[u]=++tot;
    pos[tot]=u;
    for(int v:bg[u])
    {
        dfsb(v);
    }
    ed[u]=++tot;
}


set<int>st;

void dfs(int u)
{
    int lst=0;
    int now=0;
    auto p=st.lower_bound(dfn[u]);
    for(int i=1;i<=1;i++)
    {
        if(p!=st.end()&&ed[pos[*p]]<ed[u])
        {
            continue;
        }
        if(p!=st.begin())
        {
            p--;
            if(ed[pos[*p]]>ed[u])
            {
                lst=*p;
                now=dfn[u];
                st.insert(now);
                st.erase(lst);
                continue;
            }
            p++;
        }
        now=dfn[u];
        st.insert(now);
    }
    dp[u]=st.size();
    for(int v:ag[u])
    {
        dfs(v);
    }
    if(now)
        st.erase(now);
    if(lst)
        st.insert(lst);
}

int main()
{
    sync;
    int n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int u,v;
        for(int i=2;i<=n;i++)
        {
            cin>>u;
            ag[u].push_back(i);
        }
        for(int i=2;i<=n;i++)
        {
            cin>>u;
            bg[u].push_back(i);
        }
        tot=0;
        dfsb(1);
        
        st.clear();
        dfs(1);
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,dp[i]);
        }
        cout<<mx<<endl;
        for(int i=1;i<=n;i++)
        {
            ag[i].clear();
            bg[i].clear();
        }
    }
    return 0;
}
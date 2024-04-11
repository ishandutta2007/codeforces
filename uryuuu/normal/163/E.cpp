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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
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
//const ll Mod=998244353;

vector<int>g[maxn];
int id[maxn];

int tr[maxn][26], fail[maxn], ed[maxn];
int root, cnt;
int newnode()
{
    for (int i = 0; i < 26; i++)
        tr[cnt][i] = -1;
    ed[cnt++] = 0;
    return cnt - 1;
}
void init()
{
    cnt = 0;
    root = newnode();
}
void insert(char buf[],int k)
{
    int len = strlen(buf);
    int now = root;
    for (int i = 0; i < len; i++)
    {
        if (tr[now][buf[i] - 'a'] == -1)
            tr[now][buf[i] - 'a'] = newnode();
        now = tr[now][buf[i] - 'a'];
    }
    id[k]=now;
    ed[now]++;
}
void build()
{
    queue<int>Q;
    fail[root] = root;
    for (int i = 0; i < 26; i++)
    {
        if (tr[root][i] == -1)
            tr[root][i] = root;
        else
        {
            fail[tr[root][i]] = root;
            g[0].push_back(tr[root][i]);
            Q.push(tr[root][i]);
        }
    }
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (tr[now][i] == -1)
                tr[now][i] = tr[fail[now]][i];
            else
            {
                fail[tr[now][i]] = tr[fail[now]][i];
                g[fail[tr[now][i]]].push_back(tr[now][i]);
                Q.push(tr[now][i]);
            }
        }
    }
}
// buf
int query(char buf[])
{
    int len = strlen(buf);
    int now = root;
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        now = tr[now][buf[i] - 'a'];
        int temp = now;
        while (temp != root)
        {
            res += ed[temp];
            ed[temp] = 0;
            temp = fail[temp];
        }
    }
    return res;
}

char buf[1000010];

int dfn[maxn],tot,dfned[maxn];

void dfs(int u)
{
    dfn[u]=++tot;
    for(int v:g[u])
    {
        dfs(v);
    }
    dfned[u]=tot;
}

char s[maxn];
int b[maxn];

void upd(int x,int val)
{
    while(x<maxn)
    {
        b[x]+=val;
        x+=lb(x);
    }
}

int ask(int x)
{
    int res=0;
    while(x)
    {
        res+=b[x];
        x-=lb(x);
    }
    return res;
}

int qry()
{
    int x=0,ans=0,pos=0;
    while(s[pos])
    {
        x=tr[x][s[pos]-'a'];
        ans+=ask(dfn[x]);
        pos++;
    }
    return ans;
}

int vis[maxn];

int main()
{
    int n,q;
    cin>>q>>n;
    tot=0;
    init();
    for(int i=1;i<=n;i++)
    {
        cin>>buf;
        insert(buf,i);
    }
    build();
    dfs(0);

    for(int i=1;i<=n;i++)
    {
        upd(dfn[id[i]],1);
        upd(dfned[id[i]]+1,-1);
    }
    for(int i=1;i<=n;i++)
        vis[i]=1;
    char op;
    int x;
    while(q--)
    {
        cin>>op;
        if(op=='?')
        {
            cin>>s;
            cout<<qry()<<endl;
        }
        else if(op=='+')
        {
            cin>>x;
            if(vis[x])
                continue;
            vis[x]=1;
            upd(dfn[id[x]],1);
            upd(dfned[id[x]]+1,-1);
        }
        else
        {
            cin>>x;
            if(vis[x]==0)
                continue;
            vis[x]=0;
            upd(dfn[id[x]],-1);
            upd(dfned[id[x]]+1,1);
        }
    }
    
    return 0;
}
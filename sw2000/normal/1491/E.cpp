#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int now[N],fib[30];
set<pii>s[N];
vi edg[N];
int n;
void dfs(int u=1,int f=0)
{
    for(auto v:edg[u])if(v!=f)
    {
        dfs(v,u);
        s[u].insert({now[v],v});
    }

    while(!s[u].empty()&&abs(now[u]-s[u].begin()->fi)==1)
    {
        now[u]+=s[u].begin()->fi+3;
        int v=s[u].begin()->se;
        now[u]/=2;

        s[u].erase(s[u].begin());
        for(auto i:s[v])s[u].insert(i);
        s[v].clear();
    }
//    cout<<u<<' '<<now[u]<<endl;
    if(now[u]==0)now[u]++;
    while(!s[u].empty()&&abs(now[u]-s[u].begin()->fi)==1)
    {
        now[u]+=s[u].begin()->fi+3;
        int v=s[u].begin()->se;
        now[u]/=2;

        s[u].erase(s[u].begin());
        for(auto i:s[v])s[u].insert(i);
        s[v].clear();
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    fib[0]=fib[1]=1;
    for(int i=2;i<30;i++)fib[i]=fib[i-1]+fib[i-2];

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs();
//    for(int i=1;i<=n;i++)cout<<now[i]<<endl;
    cout<<(fib[now[1]]==n?"YES":"NO")<<endl;
    return 0;
}
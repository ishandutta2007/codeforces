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
typedef vector<int> vi;
const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}


vector<int>g[maxn];
ll a[maxn];
ll sum;
void dfs(int u,int fa,map<ll,ll>mp)
{
    sum=(sum+a[u])%Mod;
//    cout<<a[u]<<endl;
    map<ll,ll>mp1;
    mp1[a[u]]++;
    for(auto it:mp)
    {
        ll x=it.first;
        ll cnt=it.second;
        ll y=gcd(x,a[u]);
        if(x==0)
            y=a[u];
        if(a[u]==0)
            y=x;
        sum=(sum+y*cnt%Mod+Mod)%Mod;
//        cout<<x<<' '<<a[u]<<' '<<y<<' '<<cnt<<endl;
        mp1[y]+=cnt;
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)
            continue;
        dfs(v,u,mp1);
    }
    return ;
}


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map<ll,ll>mp;
    dfs(1,0,mp);
    cout<<sum<<endl;
    
//    cout<<endl<<gcd(5,4)<<endl;
    return 0;
}
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



vector<int>g[maxn],d[maxn];
ll in[maxn],out[maxn];
ll a[maxn];
ll sum;


void upd(int x)
{
    sum-=in[x]*out[x];
    out[x]=g[x].size();
    in[x]=0;
    for(int i=0;i<d[x].size();i++)
    {
        int v=d[x][i];
        sum-=in[v]*out[v];
        in[v]++;
        out[v]--;
        sum+=in[v]*out[v];
        d[v].push_back(x);
    }
    d[x].clear();
}


int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(u<v)
        {
            swap(u,v);
        }
        out[u]++;
        in[v]++;
        d[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        sum+=in[i]*out[i];
    }
    cout<<sum<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int d;
        cin>>d;
        upd(d);
        cout<<sum<<endl;
    }
    
    
    return 0;
}
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

int gcd(int a,int b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}


int d[maxn];
vector<int>g[maxn];
int dep[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        int ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            d[i]=0;
            g[i].clear();
            dep[i]=-1;
        }
        queue<int>q;
        while(q.size())
            q.pop();
        int u,v;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            d[u]++;
            d[v]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(d[i]==1||d[i]==0)
            {
                dep[i]=1;
                q.push(i);
            }
        }
        while(q.size())
        {
            u=q.front();
            q.pop();
            if(dep[u]>k)
                break;
            ans++;
            for(int v:g[u])
            {
                d[v]--;
                if(d[v]<=1&&dep[v]==-1)
                {
                    dep[v]=dep[u]+1;
                    q.push(v);
                }
            }
        }
        while(q.size())
            q.pop();
        cout<<n-ans<<endl;
        
    }
    return 0;
}
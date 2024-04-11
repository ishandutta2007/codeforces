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
const int maxn=1000005;
const ll Mod=1000000007;
//const ll Mod=998244353;


int a[maxn];
int c[maxn];
int vis[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            vis[i]=1e9;
        }
        
        queue<int>q;
        while(q.size())
            q.pop();
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                vis[i]=0;
                q.push(i);
            }
        }
        int u,v;
        while(q.size())
        {
            u=q.front();
            q.pop();
            v=(u+d)%n;
            if(vis[v]==1e9)
            {
                vis[v]=vis[u]+1;
                q.push(v);
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(vis[i],mx);
        }
        if(mx==1e9)
            cout<<-1<<endl;
        else
            cout<<mx<<endl;
        
    }
    return 0;
}
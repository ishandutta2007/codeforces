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
//const ll Mod=1000000007;
const ll Mod=998244353;

struct node
{
    ll x,y;
}a[7050];
int vis[7050];

bool cmp(node a,node b)
{
    return a.y<b.y;
}

vector<int>g[7050];
int d[7050];

queue<int>q;

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].x;
    for(int i=0;i<n;i++)
        cin>>a[i].y;
    sort(a,a+n,cmp);
    ll sum=0;
    int f;
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if((a[i].x|a[j].x)==a[i].x)
            {
                g[i].push_back(j);
                d[j]++;
            }
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(d[i]==0)
        {
            vis[i]=1;
            q.push(i);
        }
    }
    
    
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            d[v]--;
            if(d[v]<=0&&vis[v]==0)
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
    int cnt=0;
    
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            sum+=a[i].y;
            cnt++;
        }
    }
    if(cnt<2)
        cout<<0<<endl;
    else
        cout<<sum<<endl;
    
    return 0;
}
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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000010;
const ll Mod=1000000007;
//const ll Mod=998244353;


int a[maxn];
int b[maxn];
vector<int>g[maxn];

struct node
{
    int x,y;
}s[maxn];

int vis[maxn];
int v[maxn];

int c[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    rep(i,1,n)
        cin>>a[i];
    rep(i,1,m)
    {
        cin>>s[i].x>>s[i].y;
        g[s[i].x].push_back(i);
        g[s[i].y].push_back(i);
        b[s[i].x]++;
        b[s[i].y]++;
    }
    queue<int>q;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]<=a[i])
        {
            q.push(i);
            v[i]=1;
        }
    }
    int cnt=0;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int x=g[u][i];
            if(vis[x]==0)
            {
                int id=s[x].x;
                b[id]--;
                if(b[id]<=a[id]&&v[id]==0)
                {
                    q.push(id);
                    v[id]=1;
                }
                id=s[x].y;
                b[id]--;
                if(b[id]<=a[id]&&v[id]==0)
                {
                    q.push(id);
                    v[id]=1;
                }
                vis[x]=1;
                c[cnt++]=x;
            }
        }
    }
//    cout<<cnt<<endl;
    if(cnt!=m)
    {
        cout<<"DEAD"<<endl;
    }
    else
    {
        cout<<"ALIVE"<<endl;
        for(int i=cnt-1;i>=0;i--)
            cout<<c[i]<<' ';
        cout<<endl;
    }
    
    return 0;
}
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
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;


int d[maxn];
vector<int>g[maxn];
int b[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int u,v;
        for(int i=1;i<=n;i++)
        {
            d[i]=1;
            g[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
        }
        int cnt=0;
        for(int u=1;u<=n;u++)
        {
//            cout<<u<<' '<<d[u]<<endl;
            if(d[u]%3==0)
            {
                b[cnt++]=u;
                continue;
            }
            for(int i=0;i<g[u].size();i++)
            {
                int v=g[u][i];
                d[v]=max(d[v],d[u]+1);
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
            cout<<b[i]<<' ';
        cout<<endl;
    }
    
    return 0;
}
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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;



vector<int>g[maxn];

struct node
{
    int x,y;
}a[maxn];
bool vis[maxn];


int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y;
        g[a[i].x].push_back(i);
        if(a[i].x!=a[i].y)
            g[a[i].y].push_back(i);
    }
    int sz=(m+1)/2;
    int ans;
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()>=sz)
        {
            mm(vis);
            for(int j=0;j<g[i].size();j++)
            {
                vis[g[i][j]]=1;
            }
            ans=m-g[i].size();
            for(int k=1;k<=n;k++)
            {
                if(k==i)
                    continue;
                if(g[k].size()<ans)
                    continue;
                int cnt=0;
                for(int j=0;j<g[k].size();j++)
                {
                    if(vis[g[k][j]]==0)
                        cnt++;
                }
                if(cnt>=ans)
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    
    return 0;
}
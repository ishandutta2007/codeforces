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
//const ll Mod=1000000007;
const ll Mod=998244353;
 

vector<int>g[maxn];
int d[maxn];
int vis[maxn];
int s[maxn];

int main()
{
    sync;
    int t;
    int n;
    int k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            d[i]=0;
            s[i]=0;
            vis[i]=0;
        }
        int u,v;
        for(int i=1;i<=n-1;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            d[u]++;
            d[v]++;
        }
        if(k==1)
        {
            cout<<n-1<<endl;
            continue;
        }
       
        
        queue<int>q;
        
        for(int i=1;i<=n;i++)
        {
            if(d[i]==1)
            {
                q.push(i);
                vis[i]=1;
            }
        }

        int sum=0;
        
        while(q.size())
        {
            u=q.front();
//            cout<<u<<' ';
            q.pop();
            for(int i=0;i<g[u].size();i++)
            {
                v=g[u][i];
//                cout<<v<<endl;
                if(vis[v])
                    continue;
//                cout<<v<<endl;
                s[v]++;
//                cout<<v<<' '<<s[v]<<endl;
                if(s[v]%k==0)
                {
                    d[v]-=s[v];
                    sum+=s[v]/k;
                    s[v]=0;
                    if(d[v]==1)
                    {
//                        cout<<v<<endl;
                        q.push(v);
                        vis[v]=1;
                    }
                }
            }
        }
//        cout<<endl;
//        for(int i=1;i<=n;i++)
//            cout<<vis[i]<<' ';
//        cout<<endl;
        cout<<sum<<endl;
        
        
    }
    return 0;
}
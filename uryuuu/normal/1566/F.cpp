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
const ll Mod=998244353;


ll dp[3],pd[3];
ll a[maxn];
vector<pll>g[maxn],st;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n+5;i++)
        {
            g[i].clear();
        }
        sort(a+1,a+n+1);
        ll l,r,pos;
        for(int i=1;i<=m;i++)
        {
            cin>>l>>r;
            pos=lower_bound(a+1,a+n+1,l)-a;
            if(pos<=n&&a[pos]<=r)
                continue;
            g[pos].push_back(mkp(l,r));
        }
        
        for(int i=1;i<=n+1;i++)
        {
            sort(g[i].begin(),g[i].end());
            st.clear();
            for(auto [l,r]:g[i])
            {
                if(st.size()&&st.back().first==l)
                    continue;
                while(st.size()&&st.back().second>=r)
                    st.pop_back();
                st.push_back(mkp(l,r));
            }
            g[i]=st;
        }
        
        for(int i=1;i<=n;i++)
        {
            g[i].push_back(mkp(a[i],a[i]));
            g[i+1].insert(g[i+1].begin(),mkp(a[i],a[i]));
        }
        
        dp[0]=a[1]-g[1][0].second;
        dp[1]=2ll*dp[0];
        int x,y,j;
        for(int i=2;i<=n;i++)
        {
            pd[0]=pd[1]=1e18;
            for(j=0;j<g[i].size()-1;j++)
            {
                l=g[i][j].first;
                r=g[i][j+1].second;
                for(x=0;x<=1;x++)
                {
                    for(y=0;y<=1;y++)
                    {
                        pd[x]=min(pd[x],dp[y]+(1ll+x)*(a[i]-r)+(2ll-y)*(l-a[i-1]));
                    }
                }
            }
            dp[0]=pd[0];
            dp[1]=pd[1];
        }
        
        ll ans=1e18;
        l=g[n+1].back().first;
        for(int y=0;y<=1;y++)
        {
            ans=min(ans,dp[y]+(2ll-y)*(l-a[n]));
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
#include<bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
#define IFD(...) __VA_ARGS__
#define IFN(...)
#define L mstr<<__LINE__<<"\n";
#define PRINT(...) __VA_ARGS__ mstr<<#__VA_ARGS__<<"\n"
#define PRT(x) mstr<<#x<<"="<<x<<"\n"
#else
#define IFD(...)
#define IFN(...) __VA_ARGS__
#define L
#define PRINT(...) __VA_ARGS__
#define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)
#define forc(i,c) for(auto _N_##i##_=c.begin(),i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++);\
                      i!=c.end();\
                      i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++))
#define forr(i,c) for(auto _N_##i##_=c.rbegin(),i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++);\
                      i!=c.rend();\
                      i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

vector< vector<int> > g;
vector<int> e;
vector<int> res;

int dfs(int v)
{
    if(res[v]!=-1)
        return res[v];
    res[v]=0;
    for(int to:g[v])
        res[v]=max(res[v],dfs(to)+(e[v]&&!e[to]));
    if(g[v].empty())
        res[v]=e[v];
    return res[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin>>n>>m;
    e.resize(n);
    for(int i=0; i<n; i++)
        cin>>e[i];
    g.resize(n);
    for(int i=0; i<m; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        g[t1].phb(t2);
    }
    int ans=0;
    res.assign(n,-1);
    for(int i=0; i<n; i++)
        ans=max(ans,dfs(i));
    cout<<ans;
}
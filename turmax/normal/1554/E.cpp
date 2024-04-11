#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
const int p=998244353;
vector <int> a[maxn];
bool used[maxn];
int sub[maxn];
int dp[maxn][2];
void dfs0(int x)
{
    used[x]=true;
    sub[x]=1;
    for(auto v:a[x]) {if(!used[v]) {dfs0(v);sub[x]+=sub[v];}}
    used[x]=false;
}
void dfs(int x,int k)
{
    used[x]=true;
    vector <pair<int,int> > z;
    vector <int> l;
    for(auto v:a[x])
    {
        if(!used[v])
        {
        dfs(v,k);
        z.push_back({dp[v][0],dp[v][1]});
        l.push_back(v);
        }
    }
    if(z.empty())
    {
        if(k==1)
        {
            dp[x][0]=1;dp[x][1]=1;
            used[x]=false;
            return;
        }
        else
        {
            dp[x][0]=1;dp[x][1]=0;
            used[x]=false;
            return;
        }
    }
    if(k==1)
    {
        long long ans=1;
        for(auto h:z) {ans*=(h.first+h.second);ans%=p;}
        dp[x][0]=ans;dp[x][1]=ans;
        used[x]=false;
        return;
    }
    else
    {
        bool ok=1;
        int cnt=0;
        long long ans=1;
        for(int i=0;i<z.size();++i)
        {
            pair <int,int> h=z[i];int v=l[i];
            if((sub[v]-1)%k==0)
            {
                ans*=h.first;ans%=p;
                ++cnt;
            }
            else if((sub[v]-1)%k==(k-1))
            {
                ans*=h.second;ans%=p;
            }
            else
            {
                ok=0;
            }
        }
        ok=(ok && ((cnt%k)==0 || (cnt%k)==(k-1)));
        if(!ok)
        {
            dp[x][0]=0;dp[x][1]=0;
            used[x]=false;
            return;
        }
        if(cnt%k==0)
        {
            used[x]=false;
            dp[x][0]=ans;
            dp[x][1]=0;
            return;
        }
        else
        {
            used[x]=false;
            dp[x][0]=0;
            dp[x][1]=ans;
            return;
        }
    }
    used[x]=false;
}
int slv(int x)
{
    dfs(0,x);
    return dp[0][0]%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;++i) {used[i]=false;a[i].clear();}
        for(int i=0;i<(n-1);++i) {int x,y;cin>>x>>y;x--;y--;a[x].push_back(y);a[y].push_back(x);}
        long long ans[n+1]={0};
        dfs0(0);
        long long u=(n-1);
        for(int i=0;i<n;++i) u=__gcd(u,(sub[i]*1LL*(sub[i]-1)));
        for(int i=1;i<=(n-1);++i)
        {
            if(u%i==0)
            {
                ans[i]=slv(i);
            }
            else
            {
                ans[i]=0;
            }
        }
        for(int i=(n-1);i>=1;i--)
        {
            for(int j=(2*i);j<=n;j+=i)
            {
                ans[i]-=ans[j];ans[i]%=p;
            }
        }
        for(int i=1;i<=n;++i) cout<<(ans[i]%p+p)%p<<' ';
        cout<<endl;
    }
    return 0;
}
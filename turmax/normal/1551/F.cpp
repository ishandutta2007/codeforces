#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=105;
vector <int> a[maxn];
bool used[maxn];
int l[maxn][maxn];
int ans;
int c;int k;
int slv1(vector <int> v,int k)
{
    int dp[v.size()+1][k+1];
    for(int i=0;i<=v.size();++i) for(int j=0;j<=k;++j) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<v.size();++i) for(int j=0;j<=k;++j)
    {
        if(j!=k) {dp[i+1][j+1]+=(dp[i][j]*v[i]);dp[i+1][j+1]%=p;}
        {dp[i+1][j]+=(dp[i][j]);dp[i+1][j]%=p;}
    }
    return dp[v.size()][k];
}
void dfs(int x)
{
    for(int i=0;i<maxn;++i) l[x][i]=0;
    l[x][0]++;
    used[x]=true;
    vector <int> z;
    for(auto v:a[x])
    {
        if(used[v]) continue;
        dfs(v);
        z.push_back(v);
        for(int i=0;i<maxn;++i) l[x][i+1]+=l[v][i];
    }
    used[x]=false;
    if(x==c)
    {
        for(int i=0;i<maxn;++i)
        {
            vector <int> v;
            for(auto h:z)
            {
                v.push_back(l[h][i]);
            }
            int o=slv1(v,k);
            ans+=o;
            ans%=p;ans+=p;ans%=p;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        ans=0;
        for(int i=0;i<maxn;++i) {a[i].clear();used[i]=false;}
        for(int i=0;i<(n-1);++i) {int x,y;cin>>x>>y;x--;y--;a[x].push_back(y);a[y].push_back(x);}
        if(k==2) {cout<<n*(n-1)/2<<endl;continue;}
        for(int i=0;i<n;++i) {c=i;dfs(i);}
        cout<<ans<<endl;
    }
    return 0;
}
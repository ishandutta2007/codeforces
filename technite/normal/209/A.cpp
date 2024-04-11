//template start//
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vpi vector<pi>
#define vpl vector<pl>
typedef double dd;
typedef long long ll;
template<typename T>
void printvector(vector<T>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<"\n";
}
template<typename T>
void printarray(T a[])
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" "; 
    }
    cout<<"\n";
}
 
void printpairs(vector<pair<int,int>>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i].F<<','<<v[i].S<<'|';
    }
    cout<<endl;
}
 
void print2d(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        printvector(v[i]);
    }
}
// checks if a number is a perfect square in almost O(1) time
long long sqroot(long long n){
    long double N = n;
    N = sqrtl(N);
    long long sq = N-2;
    sq = max(sq,0LL);
    while(sq*sq<n){
        sq++;
    } 
    if((sq*sq)==n)
        return sq;
    return -1;
}
//exponent in log(m) time
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
//template ends//
void dfs(vvi&adj,vector<bool>&visited,int a,vector<int>&depth,int parent,vector<double>&probability)
{
    double n=adj[a].size(); 
    if(a!=1) n--;
    //cout<<n<<"\n";
    for(auto i:adj[a])
    {
        if(i==parent) continue;
        visited[i]=1;
        depth[i]=depth[a]+1;
        probability[i]+=(double)probability[a]/(double)n;
        //cout<<i<<" "<<probability[i]<<"\n";
        dfs(adj,visited,i,depth,a,probability);
    }
}
int main()
{
    fast;
    int n;
    cin>>n;
    ll mod=1e9+7;
    vl dp(n+1,0);
    ll r=0,b=0;
    dp[1]=1;
    r=1;
    ll ans=1;
    for(int i=2;i<=n;i++)
    {
        if(i&1)
        {
            dp[i]=b+1;
            r+=dp[i];
            ans+=dp[i];
        }
        else
        {
            dp[i]=r+1;
            b+=dp[i];
            ans+=dp[i];
        }
        //cout<<ans<<"\n";
        dp[i]%=mod;r%=mod;b%=mod;ans%=mod;
    }
    //printvector(dp);
    cout<<ans<<"\n";

}
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
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
typedef long double ld; 
typedef double dd;
typedef long long ll;
const int MOD = 998244353; // = (119<<23)+1
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 
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
void bfs(vector<vector<bool>>&v,vvl&distance,queue<pi> g)
{
    vector<vector<bool>> vis(v.size(),vector<bool>(v[0].size(),0));   
    while(!g.empty())
    {
        int i=g.front().F;
        int j=g.front().S; 
        vis[i][j]=1;
        g.pop();
            if(i>0)
            {
                if(!vis[i-1][j])
                {
                    vis[i-1][j]=1;
                    if(distance[i-1][j]<0)
                    distance[i-1][j]=distance[i][j]+1;
                    g.push({i-1,j});
                }
            }
            if(j>0)
            {
                if(!vis[i][j-1])
                {
                    vis[i][j-1]=1;
                    if(distance[i][j-1]<0)
                    distance[i][j-1]=distance[i][j]+1;
                    g.push({i,j-1});
                }
            }
            if(i<v.size()-1)
            {
                if(!vis[i+1][j])
                {
                    vis[i+1][j]=1;
                    if(distance[i+1][j]<0)
                    distance[i+1][j]=distance[i][j]+1;
                    g.push({i+1,j});
                }
            }
            if(j<v[0].size()-1)
            {
                if(!vis[i][j+1])
                {
                    vis[i][j+1]=1;
                    if(distance[i][j+1]<0)
                    distance[i][j+1]=distance[i][j]+1;
                    g.push({i,j+1});
                }
            }
    }        
}
int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    vector<vector<bool>> v(n,vector<bool>(m));
    bool all_bad=true;
    queue<pi> good;
    vvl dist(n,vl(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            v[i][j]=0;
            if(i>0)
            {
                if(s[i-1][j]==s[i][j]) {all_bad=false;v[i][j]=1;}
            }
            if(j>0)
            {
                if(s[i][j-1]==s[i][j]) {all_bad=false;v[i][j]=1;}
            }
            if(i<n-1)
            {
                if(s[i+1][j]==s[i][j]) {all_bad=false;v[i][j]=1;}
            }
            if(j<m-1)
            {
                if(s[i][j+1]==s[i][j]) {all_bad=false;v[i][j]=1;}
            }
            if(v[i][j]) {good.push({i,j});dist[i][j]=0;}
        }
    }
    if(!all_bad)
    {
        bfs(v,dist,good);
        while(t--)
        {
            ll x,y,p;
            cin>>x>>y>>p;
            x--;y--;
            if(p<=dist[x][y])
            {
                cout<<s[x][y]<<"\n";
            }
            else
            {
                if(!dist[x][y])
                {
                    int c=(s[x][y]=='1'?1:0);
                    cout<<(p%2?1-c:c)<<"\n";
                }
                else
                {
                    p-=dist[x][y];
                    int c=(s[x][y]=='1'?1:0);
                    cout<<(p%2?1-c:c)<<"\n";
                }
            }
        }
    }   
    else
    {
        while(t--)
        {
            ll x,y,p;
            cin>>x>>y>>p;
            x--;
            y--;
            cout<<s[x][y]<<'\n';
        }
    }
}
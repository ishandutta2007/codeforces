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
    sq = max(sq,(ll)0);
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
//nCr with modulo
ll R=MOD; 
ll modInverse(ll n) { 
    return exp(n, R-2,R);
} 
ll ncr(ll n, ll r) 
{ 
    if (r==0) return 1; 
        vector<ll>fac(n+1,1); 
        for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%R; 
        return ((fac[n]*modInverse(fac[r]) % R)*modInverse(fac[n-r])%R)%R;
}
//prime factorization in log(n)____worst case-root(n)(when n is prime)//
void factorize(long long n,vpi&v) 
{ 
    int count = 0; 
    while (!(n % 2)) { 
        n >>= 1;  
        count++; 
    } 
  
    if (count) 
        v.push_back(make_pair(2,count)); 
  
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            v.push_back(make_pair(i,count));
    } 
  
    if (n > 2) 
        v.push_back(make_pair(n,1));
} 
//
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
//template ends//
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int x, int y,vector<vector<int>>&c,vector<string>&g,int N) {
    if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return 0;
    if(c[x][y] || g[x][y] == '*') return 0;     
    c[x][y] = N;
    int s = 1;
    for(int i=0;i<4;i++) s += dfs(x + d[i][0], y + d[i][1],c,g,N);
    return s;
}
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    vector<string> ans(n);
    vector<int> a;
    a.pb(-1);
    vvi connected(n,vi(m,0));
    int N=1;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
               int x=dfs(i,j,connected,s,N);
               a.pb(x);
               N++;
               ans[i]+='1';
        }

    }
    //print2d(connected);
    //printvector(a);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.') ans[i][j]='.';
            else
            {
                set<int> u;
                for(int k=0;k<4;k++)
                    {
                        int x=i+d[k][0];
                        int y=j+d[k][1];
                        if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='*')
                        u.insert(connected[x][y]);
                    }
                int answer=1;
                for(auto k:u) answer+=a[k];
                ans[i][j]=char('0'+(answer%10));
            }

            
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<'\n';
}
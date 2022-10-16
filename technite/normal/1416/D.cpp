//template start//
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
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
//intitialization->ordered_set<int>  s;.....can do all set functions.......s.order_of_key(2)(// the number of elements in the set s strictly less than 2)
//use this ->   using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(0)(print the 0-th smallest number in s(0-based)).....
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
//exponent in log(m) time
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
//nCr with modulo
ll R=MOD; 
// modinv((x-1)!)=modinv(x)*x
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
//prime factorization can be done in log(n) after a precomputaion of O(nlog(log(n)))
//(In sieve storing the smallest prime factor of each number upto n)
//sieve for spf
void sieve(int n,vi&spf)
{
    for(int i=0;i<n;i++) spf[i]=i;
    for(int i=2;i<n;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=((ll)i)*((ll)i);j<n;j+=i)
            {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
//prime factorization in root(n)//
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
//2d grids
int mv_x[]={0,0,1,-1};
int mv_y[]={1,-1,0,0};
//
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
//template ends//
//ImpPoints
//1) string insert function is way faster than loop insertion
//2)Use binary exp instead of log,pow(they work well with doubles)
//3)if accesing any index then keep check that the index exists
//4) use(int) with v.size() calculations always.
ll check=1;
struct seg{
pl mn;
}st[1<<19];
//app,psh,upd2 are for range updates and adding x to all values of the interval
/*
void app(int i,ll x,int l2,int r2)
{
    st[i].mn+=x;
    st[i].s+=x*(r2-l2+1);
    st[i].lz+=x;
}
void psh(int i,int l2,int m2,int r2)
{
    app(2*i,st[i].lz,l2,m2);
    app(2*i+1,st[i].lz,m2+1,r2);
    st[i].lz=0;
}
*/
// update at l1 to x;
int n;
void upd(ll l1,pl x, ll i=1,ll l2=0,ll r2=n-1)
{
    if(l2==r2)
    {
        st[i].mn=x;
    //    st[i].s=x;
        return;
    }
    ll m2=(l2+r2)/2;
    //psh(i,l2,m2,r2);
    if(l1<=m2)
        upd(l1,x,2*i,l2,m2);
    else
    upd(l1,x,2*i+1,m2+1,r2);
    st[i].mn=max(st[2*i].mn,st[2*i+1].mn);
    //st[i].s=st[2*i].s+st[2*i+1].s;
}
//adds x to all indexes from l1 to r1 included
/*
void upd2(int l1,int r1,ll x, int i=1,int l2=0,int r2=n-1)
{
    if(l1<=l2&&r2<=r1)
    {
        app(i,x,l2,r2);
        return;
    }
    int m2=(l2+r2)/2;
    psh(i,l2,m2,r2);
    if(l1<=m2)
        upd2(l1,r1,x,2*i,l2,m2);
    if(m2<r1)
        upd2(l1,r1,x,2*i+1,m2+1,r2);
    st[i].mn=min(st[2*i].mn,st[2*i+1].mn);
    st[i].s=st[2*i].s+st[2*i+1].s;
}
*/
pl qry(ll l1,ll r1,ll i=1,ll l2=0,ll r2=n-1)
{
    if(l1<=l2&&r2<=r1)
    /*for min*/return st[i].mn;
    ///*for sum*/return st[i].s;
    ll m2=(l2+r2)/2;
        //psh(i,l2,m2,r2);
    return max(l1<=m2?qry(l1,r1,2*i,l2,m2):pl{0ll,0ll},m2<r1?qry(l1,r1,2*i+1,m2+1,r2):pl{0ll,0ll});
    /*for sum*///return (l1<=m2?qry(l1,r1,2*i,l2,m2):0)+(m2<r1?qry(l1,r1,2*i+1,m2+1,r2):0);
}
vi size_at_query;
vi link,sz,tin;
vvi adj;
vi vis;
vi rep;
pl mn={1e18,-1};
void dfs1(int x,vi&v)
{
    v.pb(x);
    vis[x]=check;
    for(auto node:adj[x])
    {
        if(vis[node]!=check)
        {
            dfs1(node,v);
        }
    }
}
int find(int x) 
{
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
}
void unite(int a, int b) 
{
    a = find(a);
    b = find(b);
    if(a==b) return;
    if (sz[a] < sz[b]) swap(a,b);
    mn={1e18,-1};
    vi temp;
    dfs1(b,temp);
    for(auto x:temp)
    {
        tin[x]+=sz[a];
        if(tin[x]<mn.F)
        {
            mn.F=tin[x];
            mn.S=x;
        }
    }
    if(tin[rep[a]]<mn.F)
    {
        mn.S=rep[a];
    }
    //cout<<a<<" "<<b<<" "<<mn.S<<" "<<temp.sz()<<" "<<tin[rep[a]]<<" "<<rep[a]<<endl;
    for(auto x:temp)
    {
        rep[x]=mn.S;
    }
    check++;
    sz[a] += sz[b];
    link[b] = a;
}
int main()
{
    fast;   
    int m,q;
    cin>>n>>m>>q;
    adj=vvi(n+1);
    vl perm(n+1);
    for(int i=1;i<=n;i++) cin>>perm[i];
    link=sz=tin=vis=rep=vi(n+1);
    size_at_query=vi(q+1);
    vpi edges(m+1),query(q+1);
    vector<bool> del(m+1,0);
    for(int i=1;i<=m;i++)
    {
        cin>>edges[i].F>>edges[i].S;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>query[i].F>>query[i].S;
        if(query[i].F==2) del[query[i].S]=1;
    }
    for (int i = 1; i <= n; i++) 
    {
        link[i] = i;
        sz[i]=1;
        tin[i]=0;
        vis[i]=0;
        rep[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(!del[i])
        {
            unite(edges[i].F,edges[i].S);
            adj[edges[i].F].pb(edges[i].S);
            adj[edges[i].S].pb(edges[i].F);
        }
    }
    //for(int i=1;i<=n;i++) cout<<tin[i]<<" ";
    //    cout<<'\n';
    vpi answering;
    for(int i=q;i>=1;i--)
    {
        if(query[i].F==1)
        {
            //cout<<query[i].S<<" "<<rep[query[i].S]<<" dfsafa"<<endl;
            answering.pb({rep[query[i].S],sz[find(query[i].S)]});
        }
        else
        {
            unite(edges[query[i].S].F,edges[query[i].S].S);
            adj[edges[query[i].S].F].pb(edges[query[i].S].S);
            adj[edges[query[i].S].S].pb(edges[query[i].S].F);
        }
    }
    //for(int i=1;i<=n;i++) cout<<tin[i]<<" ";
    //    cout<<'\n';
    
    ll offset=0;
    vi time_in(n+1);
    for(int i=1;i<=n;i++)
    {
        if(find(i)==i)
        {
            vi temp;
            dfs1(i,temp);
            check++;
            for(auto x:temp)
            {
                time_in[x]=tin[x]+offset;
                upd(time_in[x],{perm[x],time_in[x]});
            }
            offset+=temp.size();
        }
    }
    //for(int i=1;i<=n;i++) cout<<time_in[i]<<" ";
    //    cout<<'\n';
    reverse(answering.begin(),answering.end());
    for(int i=0;i<answering.size();i++)
    {
        int L = time_in[answering[i].F];
        int R=L+answering[i].S-1;
        pl x=qry(L,R);
        //cout<<x.F<<" "<<x.S<<endl;
        //cout<<L<<" "<<R<<endl;
        cout<<x.F<<'\n';
        if(x.F!=0)
            upd(x.S,{0,x.S});
    }
}
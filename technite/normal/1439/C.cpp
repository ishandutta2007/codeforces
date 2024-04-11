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
int n, q;
const int N=4e5+15;
int a[N], c[N];
ll sum[4*N],mn[4*N],lazy[4*N];
void propogate(ll node, ll L, ll R)
{
    if(L!=R)
        lazy[node*2]=lazy[node*2+1]=lazy[node];
    sum[node]=lazy[node]*(R-L+1);
    mn[node]=lazy[node];
    lazy[node]=0;
}
void build(ll node, ll L, ll R)
{
    if(L==R)
    {
        sum[node]=a[L];
        mn[node]=a[L];
        return;
    }
    ll M=(L+R)>>1;
    build(node*2, L, M);
    build(node*2+1, M+1, R);
    sum[node]=sum[node*2]+sum[node*2+1];
    mn[node]=min(mn[node*2],mn[node*2+1]);
}

void update(ll node, ll L, ll R, ll i, ll j, ll val)
{
    if(lazy[node])
        propogate(node, L, R);
    if(j<L || i>R)
        return;
    if(i<=L && R<=j)
    {
        sum[node]=val*(R-L+1);
        mn[node]=val;
        if(L!=R)
        {
            lazy[node*2]=val;
            lazy[node*2+1]=val;
        }
        return;
    }
    ll M=(L+R)>>1;
    update(node*2, L, M, i, j, val);
    update(node*2+1, M+1, R, i, j, val);
    sum[node]=sum[node*2]+sum[node*2+1];
    mn[node]=min(mn[node*2],mn[node*2+1]);
}
ll query(ll node, ll L, ll R, ll i, ll j)
{
    if(lazy[node])
        propogate(node, L, R);
    if(j<L || i>R)
        return 0;
    if(i<=L && R<=j){
        return sum[node];
    }
    ll M=(L+R)>>1;
    return query(node*2, L, M, i, j)+query(node*2+1, M+1, R, i, j);
}
void binarysearch(int x,int y)
{
    int l=1,r=x;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        ll val=query(1,1,n,mid,mid);
        if(val>y) 
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
        //cout<<l<<" "<<r<<endl;
    }
    if(l<=x)
    {
        update(1,1,n,l,x,y);
    }
}
ll money;
ll ans(ll id, ll L, ll R, ll x){
    if(lazy[id])
        propogate(id,L,R);
    ll range=0;
    if (R<x)
    {
        return 0;
    }
    if(mn[id]>money)
    {
        return 0;
    }   
    if (x<=L)
    {
        if(sum[id]<=money)
        {
            money -= sum[id];
            range+=R-L+1;
            return range;
        }
    }
    ll mid=(L+R)>>1;
    range += ans(2*id,L,mid,x);
    range += ans(2*id+1,mid+1,R,x);
    return range;
}
int main()
{
    fast;   
    cin>>n>>q;
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        update(1,1,n,i,i,x);
    }
    //cout<<1<<endl<<" "<<query(1,1,n,3,3)<<endl;
    for(int i=0;i<q;i++)
    {
        ll type,x,y;
        cin>>type>>x>>y;
        if(type==1)
        {
            //cout<<"HERE1"<<endl;
            if(query(1,1,n,x,x)>=y)
            {
                continue;
            }
            if(query(1,1,n,1,1)<=y)
            {
                update(1,1,n,1,x,y);
                continue;
            }
            //cout<<"here"<<endl;
            binarysearch(x,y);
        }
        else
        {
            money=y;
            cout<<ans(1,1,n,x)<<'\n';
        }
    }
}
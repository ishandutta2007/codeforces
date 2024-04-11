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
vector<int> sieve(int n)
{
    vi spf(n+1,0);
    spf[1]=1;
    spf[2]=2;
    for(int i=3;i<=n;i++)
    {
        if(spf[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(!spf[j]) spf[j]=i;
            }
        }
    }
    return spf;
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
int main()
{
    fast;   
    int n;
    cin>>n;
    vl a(n);
    ll sum1=0,sum2=0;
    for(int i=0;i<n;i++) {cin>>a[i];sum1+=a[i];}
    int m;
    cin>>m;
    vl b(m);
    for(int i=0;i<m;i++) {cin>>b[i];sum2+=b[i];}
    long long mn=abs(sum1-sum2);
    int i1,i2;
    int cnt=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            ll x1=sum1;
            ll x2=sum2;
            x1=x1-a[i]+b[j];
            x2=x2-b[j]+a[i];
            if(abs(x1-x2)<mn)
            {
                mn=abs(x1-x2);
                i1=i;
                i2=j;
                cnt=1;
            }
        }
    }
    if(min(n,m)>1)
    {
        long long mn1=abs(sum1-sum2);
        set<pair<ll,pair<int,int>>> s;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                s.insert({(2*(a[i]+a[j])),{i,j}});
            }
        }
        pi a1,a2;
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                long long cum=sum1-sum2+2*(b[i]+b[j]);
                auto it=s.upper_bound({cum,{0,0}});
                auto it1=s.lower_bound({cum,{0,0}});
                long long x1=1e18,x2=1e18,x3=1e18;
                if(it!=s.end())
                {
                    x1=(*it).F;
                    if(abs(cum-x1)<mn1)
                    {
                        mn1=abs(cum-x1);
                        a1=(*it).S;
                        a2={i,j};
                    }
                }

                if(it!=s.begin())
                {
                    it--;
                    x2=(*it).F;
                    if(abs(cum-x2)<mn1)
                    {
                        mn1=abs(cum-x2);
                        a1=(*it).S;
                        a2={i,j};
                    }
                }
                if(it1!=s.begin())
                {
                    it1--;
                    x3=(*it1).F;
                    if(abs(cum-x3)<mn1)
                    {
                        mn1=abs(cum-x3);
                        a1=(*it).S;
                        a2={i,j};
                    }
                }
            }
        }
        if(mn1<mn)
        {
            cout<<mn1<<'\n';
            cout<<2<<'\n';
            cout<<a1.F+1<<" "<<a2.F+1<<'\n';
            cout<<a1.S+1<<" "<<a2.S+1<<'\n';
        }
        else
        {
            if(cnt)
            {
                cout<<mn<<'\n';
                cout<<1<<'\n';
                cout<<i1+1<<" "<<i2+1<<'\n';
            }
            else
            {
                cout<<mn<<'\n';
                cout<<0<<'\n'; 
            }
        }
    }
    else
    {
        if(cnt)
        {
                cout<<mn<<'\n';
                cout<<1<<'\n';
                cout<<i1+1<<" "<<i2+1<<'\n';
        }
        else
        {
                cout<<mn<<'\n';
                cout<<0<<'\n';  
        }
    }
}
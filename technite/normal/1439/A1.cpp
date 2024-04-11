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
int n,m;
vector<string> s;
vpi ans;
void flip(int i,int j)
{
    if(s[i][j]=='0') s[i][j]='1';
    else s[i][j]='0';
}
void flip1(pi x)
{
    if(s[x.F][x.S]=='0')
    {
        s[x.F][x.S]='1';
    }
    else 
    {
        s[x.F][x.S]='0';
    }
}
void ask(int r,int c)
{
    vpi zero,one;
    int n_one=0;
    for(int i=r;i<r+2;i++)
    {
        for(int j=c;j<c+2;j++)
        {
            if(s[i][j]=='0')
            { 
                zero.pb({i,j});
            }
            else
            { 
                one.pb({i,j});
                n_one++;
            }
        }
    }
    if(n_one==1)
    {
        pi a=one[0],b=zero[2],c=zero[1],d=zero[0];   
        ans.pb(a);ans.pb(b);ans.pb(c);
        flip1(a);flip1(b);flip1(c);
        ans.pb(a);ans.pb(d);ans.pb(c);
        flip1(a);flip1(d);flip1(c);
        ans.pb(a);ans.pb(b);ans.pb(d);
        flip1(a);flip1(b);flip1(d);
    }
    else if(n_one==2)
    {
        pi a=one[0],b=one[1],c=zero[1],d=zero[0];
        ans.pb(a);ans.pb(c);ans.pb(d);
        flip1(a);flip1(c);flip1(d);
        ans.pb(b);ans.pb(c);ans.pb(d);
        flip1(b);flip1(c);flip1(d);   
    }
    else if(n_one==3)
    {
        pi a=one[0],b=one[1],c=one[2],d=zero[0];
        ans.pb(a);ans.pb(b),ans.pb(c);
        flip1(a);flip1(b);flip1(c);
    }
    else if(n_one==4)
    {
        pi a=one[0],b=one[1],c=one[2],d=one[3];
        ans.pb(a);ans.pb(b);ans.pb(c);
        flip1(a);flip1(b);flip1(c);
        ans.pb(a);ans.pb(b);ans.pb(d);
        flip1(a);flip1(b);flip1(d);
        ans.pb(c);ans.pb(d);ans.pb(b);
        flip1(c);flip1(d);flip1(b);
        ans.pb(a);ans.pb(c);ans.pb(d);
        flip1(a);flip1(c);flip1(d);
    }
}
void print(vpi v)
{
    cout<<v.size()/3<<'\n';
    for(int i=0;i<v.size();i+=3)
    {
        cout<<v[i].F+1<<" "<<v[i].S+1<<" "<<v[i+1].F+1<<" "<<v[i+1].S+1<<" "<<v[i+2].F+1<<" "<<v[i+2].S+1<<"\n";        
    }

}
int main()
{
    TT
    {
        cin>>n>>m;
        s=vector<string>(n);
        for(int i=0;i<n;i++) cin>>s[i];
        ans.clear();
        if(n%2)
        {
            for(int i=0;i<m;i++)
            {
                if(s[n-1][i]=='1')
                {
                    ans.pb({n-1,i});
                    ans.pb({n-2,i});
                    flip(n-1,i);
                    flip(n-2,i);
                    if(i==0)
                    {
                        ans.pb({n-2,i+1});
                        flip(n-2,i+1);
                    }
                    else
                    {
                        ans.pb({n-2,i-1});
                        flip(n-2,i-1);
                    }
                }
            }
        }
        if(m%2)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(s[i][m-1]=='1')
                {
                    ans.pb({i,m-1});
                    flip(i,m-1);
                    if(i==0)
                    {
                        ans.pb({i,m-2});
                        ans.pb({i+1,m-2});
                        flip(i,m-2);
                        flip(i+1,m-2);
                    }
                    else
                    {
                        ans.pb({i-1,m-1});
                        ans.pb({i-1,m-2});
                        flip(i-1,m-1);
                        flip(i-1,m-2);
                    }
                }
            }
            m--;
        }
        if(n%2) n--;
        for(int i=0;i<n;i+=2)
        {
            for(int j=0;j<m;j+=2) ask(i,j);
        }
        print(ans);
    }

}
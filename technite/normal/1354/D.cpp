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
void update(int i, int add,vi&fen) 
{
    while (i > 0 && i < fen.size())
    {
        fen[i] += add;
        i += (i & (-i));
    }
}
 
int sum(int i,vi&fen) 
{
    int s = 0;
    while (i > 0)
    {
        s += fen[i];
        i = i - (i & (-i));
    }
    return s;
}

int main()
{
    fast;
    
        int n,q;
        cin>>n>>q;
        vi fen(n+1,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            update(a,1,fen);
        }
        while(q--)
        {
            int x;
            cin>>x;
            if(x>0)
            {
                update(x,1,fen);
                continue;
            }
            x*=-1;
            int low=0,high=n;
            while(low<high)
            {
                int mid=(high+low)/2;
                int y=sum(mid,fen);
                if(y>=x) high=mid;
                else low=mid+1;
            }
            update(low,-1,fen);

        }

        int ans=sum(n,fen);
        if(!ans) cout<<0<<'\n';
        else
        {
            for(int i=0;i<=n;i++)
            {
                if(sum(i,fen))
                {
                    cout<<i<<'\n';
                    break;
                }
            }
        }

    
}
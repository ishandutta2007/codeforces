#include <bits/stdc++.h>
using namespace std;
#define printint(v) copy(begin(v), end(v), ostream_iterator<int>(cout," "))
#define printintv(s,e) copy(s,e, ostream_iterator<int>(cout," "))
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits (for ints only diff for ll)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
#pragma GCC optimize ("-O2")
const int MOD = 1e9+7;
inline void fastio()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int main()
{
    fastio();
    ll n,m,k;
    cin>>n>>m>>k;
    if(k==1)
    {
        cout<<"NO"<<ln;
    }
    else
    {
        ll z = gcd(n*m,k);
        ll x = n*m;
        x=x/z;
        if(k/z>=3)
        {
            cout<<"NO"<<ln;
        }
        else
        {
            cout<<"YES"<<ln;
            cout<<"0 0"<<ln;
            if(k%2==0)
            {
                k=k/2;
                cout<<n/gcd(n,k)<<" 0"<<ln;
                k=k/gcd(n,k);
                cout<<"0 "<<m/k;
            }
            else
            {
                if(gcd(n,k)>1)
                {
                    cout<<2*n/gcd(n,k)<<" 0"<<ln;
                    k=k/gcd(n,k);
                    cout<<"0 "<<m/k;
                }
                else
                {
                     cout<<n/gcd(n,k)<<" 0"<<ln;
                    k=k/gcd(n,k);
                    cout<<"0 "<<2*m/k;
                }
            }
        }
    }
    return 0;
}
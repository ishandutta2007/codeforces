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
int main()
{
    fastio();
    ll n,m;
    cin>>n>>m;
    ll maxi=0,mini=1e9;
    ll num = n/2 + n%2;
    if(m>=num) mini=0;
    else
    {
    	mini = n - m*2;
    }
    ll l=0,r=n,mid;
    while(l<=r)
    {
    	mid = (l+r)/2;
    	//cout<<mid<<ln;
    	if(mid*(mid-1)/2>=m && (mid-1)*(mid-2)/2<m)
    	{
    		break;
    	}
    	else if(mid*(mid-1)/2>=m)
    	{
    		r = mid-1;
    	}
    	else
    	{
    		l=mid+1;
    	}
    }
    maxi = n-mid;
   // cout<<mid<<ln;
    if(n==1) mini=1,maxi=1;
    cout<<mini<<" "<<maxi<<ln;
    return 0;
}
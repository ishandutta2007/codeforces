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
#define N1 101
#define N2 101
#define K1 11
#define K2 11
#define MOD 100000000
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
   int n1,n2,k1,k2;
   long long C[N1][N2][K1][K2];
inline void fastio()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main()
{
   fastio();
   memset(C,0,sizeof C);
   cin>>n1>>n2>>k1>>k2;
   forn(f,n1+1)
   {
   	forn(h,n2+1)
   	{
   		forn(kf,k1+1)
   		{
   			forn(kh,k2+1)
   			{
   				ll ans;
   				if(f+h==0) ans=1;
   				else
   				{
   					ans=0;
   					if(f>0 && kf>0) ans= (ans+C[f-1][h][kf-1][k2])%MOD;
   					if(h>0 && kh>0) ans= (ans+C[f][h-1][k1][kh-1])%MOD;
   				}
   				C[f][h][kf][kh] = ans;
   			}
   		}
   	}
   }
   cout<<C[n1][n2][k1][k2]<<endl;
    return 0;
}
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
    int n,m;
    cin>>n>>m;
    char a[n][m];
    forn(i,n)
    {
    	forn(j,m)
    	{
    		cin>>a[i][j];
    	//	cout<<a[i][j];
    	}
    	//cout<<ln;
    }
    bool done[n][m]={0};
    int counter;
    forn(i,n)
    {
    	counter=0;
    	forn(j,m)
    	{
    		if(a[i][j]=='#')
    		{
    			counter++;
    		}
    		else
    		{
    			counter=0;
    		}
    		if(counter>=3 && i+2<=n-1)
    		{
    			if(a[i+2][j-1]=='#' && a[i+2][j-2]=='#' && a[i+2][j]=='#' && a[i+1][j-2]=='#' && a[i+1][j]=='#')
    			{
    			//	cout<<i<<" "<<j<<ln;
    				bool x = done[i+1][j-1];
    				//cout<<x<<ln;
    				forsn(r,i,i+3)
    				{
    					forsn(q,j-2,j+1)
    					{
    						done[r][q]=1;
    					}
    				}
    				done[i+1][j-1] = x;
    			}
    		}
    	}
    }
    bool answer=1;
    forn(i,n)
    {
    	forn(j,m)
    	{
    		//cout<<a[i][j]<<" ";
    		if(a[i][j]=='#' && done[i][j]!=1)
    		{
    		//	cout<<i<<" "<<j<<ln;
    			answer=0;
    			break;
    		}
    	}
    }
    if(answer==1)
    {
    	cout<<"YES";
    }
    else
    {
    	cout<<"NO";
    }
    return 0;
}
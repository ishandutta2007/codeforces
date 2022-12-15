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
    int n;
    cin>>n;
    int odd[n]={0};
    int even[n]={0};
    ll b[n]={0};
    ll tot[n]={0};
    forn(i,n)
    {
        ll a;
        cin>>a;
     //   cout<<a<<ln;
        while(a>0)
        {
            if(a%2==1)
            {
                b[i]++;
            }
            a=a/2;
        }
     //   cout<<b[i]<<ln;
    }
    tot[0]=b[0];
    if(tot[0]%2==1) odd[0]++;
    else
    {
        even[0]++;
    }
    forsn(i,1,n)
    {
        odd[i]=odd[i-1];
        even[i]=even[i-1];
        tot[i]=tot[i-1]+b[i];
        if(tot[i]%2==1) odd[i]++;
        else
        {
            even[i]++;
        }
    }
    ll answer=0;
    forn(i,n)
    {
        ll m=b[i];
        int j;
        for(j=i+1;j<=min(n-1,i+127);j++)
        {
            m=max(m,b[j]);
            if(i==0)
            {
                if(2*m<=tot[j] && (tot[j])%2==0)
                {
                    answer++;
                }
            }
            else
            {
                if(2*m<=(tot[j]-tot[i-1]) && (tot[j]-tot[i-1])%2==0)
                {
                    answer++;
                }
            }
      //      cout<<answer<<ln;
        }
        if(i==0 || tot[i-1]%2==0)
        {
            answer+=(even[n-1]-even[min(n-1,j-1)]);
        }
        else
        {
            answer+=(odd[n-1]-odd[min(n-1,j-1)]);
        }
    //    cout<<answer<<ln;
    }
    
    cout<<answer;
    return 0;
}
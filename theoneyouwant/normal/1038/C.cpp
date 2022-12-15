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
    int a[n],b[n];
    forn(i,n)
    {
        cin>>a[i];
    }
    forn(i,n)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int p1 = n-1;
    int p2= n-1;
    ll ascore=0,bscore=0;
    for(int i=n-1;i>=0;i--)
    {
        if(p1<0)
        {
            p2--;
            bscore+=b[p2];
            p2--;
            continue;
        }
        else if(p2<0)
        {
            
            ascore+=a[p1];
            p1-=2;
            continue;
        }
        if(a[p1]>=b[p2])
        {
            ascore+=a[p1];
            p1--;
        }
        else
        {
            p2--;
        }
        if(p1<0)
        {
            bscore+=b[p2];
            p2--;
            continue;
        }
        else if(p2<0)
        {
            p1--;
            continue;
        }
        else if(a[p1]>=b[p2])
        {
            p1--;
            continue;
        }
        else
        {
            bscore+=b[p2];
            p2--;
            continue;
        }
    }
    cout<<ascore-bscore;
    return 0;
}
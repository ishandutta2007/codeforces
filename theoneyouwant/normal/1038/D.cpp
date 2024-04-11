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
    vector<int> positive,negative;
    ll counter=0;
    if(n==1)
    {
        int a;
        cin>>a;
        cout<<a;
    }
    else
    {
        forn(i,n)
        {
            ll a;
            cin>>a;
            if(a>=0) positive.pb(a);
            else
            {
                negative.pb(a);
            }
        }
        if(positive.size()>0 && negative.size()>0)
        {
            forstl(i,positive)
            {
                counter+=i;
            }
            forstl(i,negative)
            {
                counter+=abs(i);
            }
            cout<<counter<<ln;
        }
        else if(positive.size()>0)
        {
            sort(positive.begin(),positive.end());
            vector<int>::iterator it = positive.begin();
            counter-=(ll)2*(ll)(*it);
            forstl(i,positive)
            {
                counter+=i;
            }
            cout<<counter;
        }
        else if(negative.size()>0)
        {
            sort(negative.begin(),negative.end());
            vector<int>::iterator it = negative.end();
            it--;
            counter-=(ll)2*abs((ll)(*it));
            forstl(i,negative)
            {
                counter+=abs(i);
            }
            cout<<counter;
        }
    }
    return 0;
}
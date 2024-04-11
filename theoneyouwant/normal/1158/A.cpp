//By TheOneYouWant

#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime ((double)clock()/CLOCKS_PER_SEC)
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
    c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;

const int LIM=1e5+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;
signed main(){
    fastio;
    
    ll n,m;
    cin>>n>>m;
    ll ma = 0;
    ll giv = 0;
    ll big1,big2;
    vector<ll> v;
    forn(i,n){
        ll x;
        cin>>x;
        v.pb(x);
        ma = max(ma,x);
        giv += x*m;  
    }
    bool p=1;
    sort(v.begin(),v.end(),greater<ll>());
    big1 = v[0];
    big2 = v[1];
    // int ptr = 0;
    vector<ll> v2;
    forn(i,m){
        ll x;
        cin>>x;
        if(ma>x) p=0;
            v2.pb(x);
        // if(i==m-2) ptr++;
    }
    sort(v2.begin(),v2.end(),greater<ll>());
    forn(i,v2.size()-1){
        // cout<<i<<" "<<v2[i]<<ln;
        if(p) giv+=(v2[i]-v[0]);
        // cout<<v[0]<<ln;
    }
    // cout<<giv<<ln;
    if(v2[v2.size()-1]!=v[0] && p) giv+=v2[v2.size()-1]-v[1];
    // cout<<v2[v2.size()-2]<<" "<<v2[v2.size()-1]<<" "<<v[1]<<ln;


    if(p) cout<<giv<<ln;
    else cout<<-1<<ln;


    return 0;
}
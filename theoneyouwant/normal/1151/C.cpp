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


const ll LIM=1e5+5, MOD=1e9+7;
const ld EPS = 1e-9;

ll precomp[64];
ll lo[64];
ll le[64];

ll solve(ll num){
    // num%=MOD;
    if(num==0) return 0;
    ll h = num;
    ll cnt=0;
    h++;
    // cout<<h<<ln;
    while(h){
        h=h/2;
        cnt++;
    }
    cnt--;
    // cout<<cnt<<ln;
    ll ans = precomp[cnt-1];
    ll k;   
    if((cnt-1)%2==0){
        k = le[cnt-1];
    }
    else{
        k = lo[cnt-1];
    }
    // cout<<k<<ln;
    k%=MOD;
    num%=MOD;
    ll diff = num - (1LL<<(cnt))+1;
    diff%=MOD;
    ans%=MOD;
    ans+=diff*k;
    ans%=MOD;
    ans+=(diff)*(diff-1);
    ans%=MOD;
    return ans;
}

// int t,n,m,k,x,y,w;
signed main(){
    fastio;
    
    ll l,r;
    cin>>l>>r;
    forn(i,64) precomp[i] = 0;
    ll lodd=1, leven=2;
    bool ptr=1;
    forsn(i,0,64){
        ll ans=0;
        if(ptr==1){
            ll k = lodd;
            ll y = (1LL<<i);
            y%=MOD;
            ans = y*(y-1);
            ans%=MOD;
            ans += (lodd%MOD)*y;
            ans%=MOD;
            lodd = lodd+2*(1LL<<i);
        }
        else{
            ll k = leven;
            ll y = (1LL<<i);
            y%=MOD;
            ans = y*(y-1);
            ans%=MOD;
            ans+=(leven%MOD)*y;
            ans%=MOD;
            leven = leven+2*(1LL<<i);
        }
        ptr = 1-ptr;
        if(i==0){
            precomp[i] = ans;
            lo[i] = lodd%MOD;
            le[i] = leven%MOD;
            continue;
        }
        precomp[i] = (ans+precomp[i-1])%MOD;
        lo[i] = lodd%MOD;
        le[i] = leven%MOD;
    }
    // cout<<le[0]<<" "<<lo[0]<<ln;
    // forn(i,64) cout<<i<<" "<<precomp[i]<<ln;
    ll fin = 0;
    fin = (solve(r)%MOD)-(solve(l-1)%MOD);
    fin%=MOD;
    fin+=MOD;
    fin%=MOD;
    cout<<fin<<ln;
    //forn(i,30) cout<<i<<" " <<precomp[i]<<ln;

    return 0;
}
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

const int LIM=1e6+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;


int link[LIM] = {0};
int size[LIM] = {0};

int find(int x){
    int a = x;
    while(x!=link[x]){
        x = link[x];
    }
    link[a] = x;
    return x;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(size[a]<size[b]) swap(a,b);
    size[a]+=size[b];
    link[b] = a;
}

ll fastpow(ll a, ll p){
    if(p==0) return 1;
    ll z = fastpow(a,p/2);
    z = (z*z) % MOD;
    if(p%2) z = (z*a)%MOD;
    return z;
}


signed main(){
    fastio;

    forn(i,LIM) link[i] = i;
    forn(i,LIM) size[i] = 1;
    
    ll p,k;
    cin>>p>>k;

    forn(i,p){
        // cout<<i<<" "<<(k*i)
        unite((k*i)%p,i);
    }

    if(k==0){
        cout<<fastpow(p,p-1)<<ln;
    }
    else if(k==1){
        cout<<fastpow(p,p)<<ln;
    }
    else{
        set<int> s;
        forn(i,p){
            s.insert(find(i));
        }
        // cout<<s.size()<<ln;
        cout<<fastpow(p,s.size()-1)<<ln;
    }



    return 0;
}
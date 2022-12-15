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
const int MAXN = 6e5+5;
const int INF = 1e9;

pair<int, int> t[4*MAXN];
int lazy[4*MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        // cout<<tl<<" ";
        t[v] = make_pair(a[tl], tl);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void push(int v) {
    t[v*2].fi += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1].fi += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v].fi += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

p32 query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return mp(-INF,-INF);
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}





const int LIM=1e5+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;
signed main(){
    fastio;
    
    int n;
    cin>>n;

    vp32 v1,v2;
    v32 va1,va2;

    map<int,int> ind, comp;
    forn(i,n){
        int a,b;
        cin>>a>>b;
        if(a<b){
            v1.pb(mp(a,b));
            va1.pb(a);
        }
        else{
            v2.pb(mp(b,a));
            va2.pb(b);
        }
        comp[a] = b;
        ind[b] = i+1;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(va1.begin(),va1.end());
    sort(va2.begin(),va2.end());

    v32 ans1, ans2;
    // int ans = 0;

    if(v1.size()!=0){
        int n = v1.size();
        int a[n];
        forn(i,n) a[i] = v1[i].se;
        build(a,1,0,n-1);
        p32 f = query(1,0,n-1,0,n-1);
        ans1.pb(f.fi);
        while(true){
            // cout<<f<<ln;
            update(1,0,n-1,f.se,f.se,-INF);
            auto it = lower_bound(va1.begin(),va1.end(),f.fi);
            if(it == va1.begin()) break;
            it--;
            int x = it-va1.begin();
            f = query(1,0,n-1,0,x);
            if(f.fi <= 0) break;
            ans1.pb(f.fi);
        }   
    }
    // cout<<ans1.size()<<ln;
    forn(i,4*MAXN) t[i] = mp(0,0);
    forn(i,4*MAXN) lazy[i] = 0;
    if(v2.size()!=0){
        int n = v2.size();
        int a[n];
        forn(i,n) a[i] = v2[i].se;
        build(a,1,0,n-1);
        p32 f = query(1,0,n-1,0,n-1);
        ans2.pb(comp[f.fi]);
        while(true){
            update(1,0,n-1,f.se,f.se,-INF);
            auto it = lower_bound(va2.begin(),va2.end(),f.fi);
            if(it == va1.begin()) break;
            it--;
            int x = it-va2.begin();
            f = query(1,0,n-1,0,x);
            if(f.fi <= 0) break;
            ans2.pb(comp[f.fi]);
        }  
    }

    reverse(ans2.begin(),ans2.end());

    if(ans1.size()<ans2.size()) swap(ans1,ans2);
    cout<<ans1.size()<<ln;
    forstl(r,ans1) cout<<ind[r]<<" ";
    cout<<ln;

    // cout<<ans1.size()<<" "<<ans2.size()<<ln;

    return 0;
}
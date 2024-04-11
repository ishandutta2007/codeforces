#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(ll it=(st);it<(ll)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef unsigned long long ll; 
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
const ll INF=(ll)1e9; 
const double EPS=(ld)1e-7;


// segment tree
struct Tree {
    typedef ll T;
    const T LOW = 0;
    T f(T a, T b) {return a|b;}
    ll n;
    vi s;
    vi lazy;
    Tree() {}
    Tree(ll m,vi c) {
        n = 1; while (n < m) n *= 2;
        s.assign(n + m, 0);
        s.resize(2 * n, LOW);
        lazy.assign(2*n, 0);
        rep(i,0,m)s[i+n]=(1LL<<c[i]);
        for (ll i = n; i --> 1; )
            s[i] = f(s[i * 2], s[i*2 + 1]);
    }
    void push(ll pos){
        if(!lazy[pos] || pos>=n )return;
        lazy[pos]=0;
        s[2*pos]=s[2*pos+1]=s[pos];
        lazy[2*pos]=lazy[2*pos+1]=1;
    }
    void upd(ll a, ll b,ll c) { return up(1, a, b, 0, n,c); }
    void up(ll pos, ll a, ll b, ll x, ll y,ll c) {
        if (a >= b) return;
        push(pos);
        if (a == x && b == y){
            lazy[pos]=1;
            s[pos]=(1LL<<c);
            return;
        }
        ll m = (x + y) / 2;
        up(2 * pos, a, min(b, m), x, m,c);
        up(2 * pos + 1, max(a, m), b, m, y,c);
        s[pos]=f(s[pos*2],s[pos*2+1]);
    }
    T query(ll a, ll b) { return que(1, a, b, 0, n); }
    T que(ll pos, ll a, ll b, ll x, ll y) {
        if (a >= b) return LOW;
        push(pos);
        if (a == x && b == y) return s[pos];
        ll m = (x + y) / 2;
        return f(que(2 * pos, a, min(b, m), x, m),
                que(2 * pos + 1, max(a, m), b, m, y));
    }
};

vi st,en;
vvi g;
ll cnt=0;
void dfs(ll n,ll p){
   st[n]=cnt++; 
   for(ll c:g[n])if(c!=p)dfs(c,n);
   en[n]=cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    st.resize(n);
    en.resize(n);
    g.resize(n);
    vi c(n);
    rep(i,0,n)cin>>c[i],--c[i];
    rep(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0,-1);
    //rep(i,0,n){
     //   cout<<i+1<<" "<<st[i]<<" "<<en[i]<<endl;
    //}
    vi c2(n);
    rep(i,0,n){
        c2[st[i]]=c[i];
    }
    Tree T(n,c2);
    rep(i,0,m){
        ll t;
        cin>>t;
        if(t==1){
            ll v,c;
            cin>>v>>c;
            --v,--c;
            T.upd(st[v],en[v],c);
        }
        else{
            ll v;
            cin>>v;
            --v;
            cout<<__builtin_popcountll(T.query(st[v],en[v]))<<"\n";
        }
        //rep(i,T.n,T.s.size())cout<<T.s[i]<<" ";cout<<endl; 
    }
    return 0;
}
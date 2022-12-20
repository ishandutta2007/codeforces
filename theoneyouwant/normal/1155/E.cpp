//By TheOneYouWant

#pragma GCC optimize ("-O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
#define ln endl
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

const int LIM=1e5+5, MOD=1e6+3;
const ld EPS = 1e-9;

int fastpow(int a, int p){
    if(p==0) return 1;
    ll z = fastpow(a,p/2);
    z = (z*z)%MOD;
    if(p%2) z = (z*a)%MOD;
    return z;
}


int gauss (vector <vector<ll> > a, vector<ll> & ans){
    int n = (int) a.size();
    int m = (int) a[0].size()-1;

    vector<int> where(m,-1);
    for(int col=0, row=0;col<m && row<n; ++col){
        int sel = row;
        for(int i=row;i<n;++i){
            if(abs(a[i][col]) > abs(a[sel][col])){
                sel = i;
            }
        }
        if(abs(a[sel][col])<EPS) continue;
        for(int i=col; i<=m; ++i){
            swap(a[sel][i],a[row][i]);
        }
        where[col] = row;

        for(int i=0;i<n;++i){
            if(i!=row){
                ll c = (a[i][col]*fastpow(a[row][col],MOD-2))%MOD;
                for(int j=col;j<=m;++j){
                    a[i][j] -= (a[row][j]*c)%MOD;
                    if(a[i][j]<0) a[i][j]+=MOD;
                }
            }
        }
        ++row;
    }
    ans.assign(m,0);
    for(int i=0;i<m;++i){
        if(where[i]!=-1){
            ans[i] = (a[where[i]][m]*fastpow(a[where[i]][i],MOD-2))%MOD;
        }
    }
    for(int i=0;i<n;++i){
        ll sum=0;
        for(int j=0;j<m;++j){
            sum+=ans[j]*a[i][j];
            sum%=MOD;
        }
        if(abs(sum-a[i][m])>EPS)
            return 0;
    }
    for(int i=0;i<m;++i){
        if(where[i]==-1) return MOD;
    }
    return 1;
}

// int t,n,m,k,x,y,w;
signed main(){
    fastio;
    
    ll an[11] = {0};
    vector<vector<ll> > inp;
    forn(i,11){
        cout<<"? "<<i<<ln;
        cin>>an[i];
        ll m = 1;
        vector<ll> q;
        forn(j,11){
            q.pb(m);
            m = m*i;
            m%=MOD;
        }
        q.pb(an[i]);
        inp.pb(q);
    }
    
    vector<ll> ans;
    gauss(inp,ans);
    // forstl(r,ans) cout<<r<<" ";
    // cout<<ln;
    int ind = -1;
    forn(i,MOD){
        ll x = i;
        ll tot=0;
        ll curr = 1;
        forn(j,11){
            tot+= curr*ans[j];
            tot%=MOD;
            curr*=i;
            curr%=MOD;
        }
        if(tot==0) ind=i;
    }
    cout<<"! "<<ind<<ln;

    return 0;
}
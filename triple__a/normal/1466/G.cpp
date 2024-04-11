// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=100007;
const int K=18;
mt19937 rng(time(NULL));

int modpow(int u,int v,int mod){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}

const int mo[2]={234567899,998244353};
const int base[2]={123,321};
int n,q;
int f[N],g[N],ff[2][20*N],sum[26][N];
string s,t;


struct hsh{
    int n;
    vector<vi> hash;
    hsh(string &s):n(sz(s)),hash(2,vi(sz(s)+1,0)){
        rep(_,2) rep(i,n) hash[_][i+1]=(hash[_][i]*base[_]+s[i])%mo[_];
    }
    pii get_hash(int l,int r){
        vi res;
        res.resize(2,0);
        rep(_,2) res[_]=(hash[_][r]-hash[_][l]*ff[_][r-l]%mo[_]+mo[_])%mo[_];
        return {res[0],res[1]};
    }
};

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>q>>s>>t;
    rep(_,2) {ff[_][0]=1; rep(i,20*N-5) ff[_][i+1]=ff[_][i]*base[_]%mo[_];}
    int inv2=(mod+1)/2;
    f[0]=1, g[0]=1;
    for (int i=1;i<=n;++i) f[i]=inv2*f[i-1]%mod, g[i]=g[i-1]*2%mod;
    rep(i,n) sum[t[i]-'a'][i+1]=f[i+1];
    rep(i,26) rep1(j,n-1) sum[i][j+1]=(sum[i][j]+sum[i][j+1])%mod;
    while (q--){
        int k;
        string w;
        cin>>k>>w;
        string ts=s;
        int cur=0;
        while (cur<k&&sz(ts)<=sz(w)){
            ts=ts+t[cur]+ts;
            cur++;
        }
        if (sz(ts)<sz(w)){
            cout<<0<<"\n";
            continue;
        }
        hsh a(ts), b(w);
        int cnt=0;
        rep(i,sz(ts)-sz(w)+1) if (b.get_hash(0,sz(w))==a.get_hash(i,sz(w)+i)) cnt++;
        int cnt2[26];
        memset(cnt2,0,sizeof(cnt2));
        rep(i,sz(w)){
            if (b.get_hash(0,i)==a.get_hash(sz(ts)-i,sz(ts))&&b.get_hash(i+1,sz(w))==a.get_hash(0,sz(w)-i-1)) cnt2[w[i]-'a']++;
        }
        cnt=cnt*g[k-cur]%mod;
        rep(_,26) {
            cnt=(cnt+(sum[_][k]-sum[_][cur]+mod)*cnt2[_]%mod*g[k])%mod;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}


/*
10

*/
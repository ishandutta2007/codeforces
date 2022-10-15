// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
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
 
int dx[]={0,1,0,-1,1,-1};
int dy[]={1,0,-1,0,1,-1};
const int mod=998244353;
const int INF=LLONG_MAX/100;
const double EPS=1e-9;
const int N=1000007;
const int K=63;
 
mt19937 rng(1234);


int n,m,k;
int a[N],b[N],cnt[N],f[N],rf[N],g[N];
int C[N];

int modpow(int u,int v){
    int ans=1,t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        v>>=1, t=t*t%mod;
    }
    return ans;
}
int lowbit(int u){return u&(-u);}
void update(int u,int w){
    for (int i=u;i<=200000;i+=lowbit(i)) C[i]=(C[i]+w)%mod;   
}
int query(int u){
    int ans=0;
    for (int i=u;i>0;i-=lowbit(i)) ans=(ans+C[i])%mod;
    return ans;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>m;
    f[0]=rf[0]=1;
    for (int i=1;i<=200000;++i) f[i]=f[i-1]*i%mod;
    rf[200000]=modpow(f[200000],mod-2);
    for (int i=200000;i>0;--i) rf[i-1]=rf[i]*i%mod;
    for (int i=1;i<=200000;++i) g[i]=modpow(i,mod-2);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    int cur=1;
    rep(i,n) cnt[a[i]]++;
    for (int i=1;i<=200000;++i) update(i,cnt[i]), cur=cur*rf[cnt[i]]%mod;
    int ans=0;
    bool fk=0;
    rep(i,min(n,m)){
        ans=(ans+query(b[i]-1)*cur%mod*f[n-i-1])%mod;
        if (!cnt[b[i]]) {fk=1; break;}
        cur=cur*cnt[b[i]]%mod, cnt[b[i]]--, update(b[i],-1);
    }
    if (n<m&&!fk) ans=(ans+1)%mod;
    cout<<ans;
    return 0;
}
/*
6 6
1 2
1 3
2 4
2 5
4 6
5 6
*/
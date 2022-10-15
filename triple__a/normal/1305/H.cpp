// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
const int maxn=100007;
const int mod=998244353;
const double pi=3.1415926535;
int n,m,q,t,l[maxn],r[maxn],suml[maxn],sumr[maxn],p[maxn],s[maxn],sum[maxn],perm[maxn];
int ls[maxn],rs[maxn];
mt19937 rnd(time(NULL));
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n>>m;
    rep(i,n) cin>>l[i]>>r[i];
    rep(i,n) perm[i]=i;
    sort(perm,perm+n,[&](int u,int v){return l[u]<l[v];});
    rep(i,n) suml[i+1]=l[perm[i]];
    rep1(i,n) suml[i]+=suml[i-1];
    sort(perm,perm+n,[&](int u,int v){return r[u]<r[v];});
    rep(i,n) sumr[i+1]=r[perm[i]];
    rep1(i,n) sumr[i]+=sumr[i-1];
    cin>>q;
    rep1(i,m) ls[i]=0, rs[i]=n;
    rep(i,q) cin>>p[i]>>s[i], ls[p[i]]=s[i], rs[p[i]]=s[i];
    for (int i=2;i<=m;++i) rs[i]=min(rs[i],rs[i-1]);
    for (int i=m-1;i>0;--i) ls[i]=max(ls[i],ls[i+1]);
    cin>>t;
    int sum0=0,sum1=0;
    for (int i=1;i<=m;++i) sum0+=ls[i], sum1+=rs[i];
    if (sum0>t||sum1<t){
        cout<<"-1 -1";
        return 0;
    }
    auto check_valid=[&](vi &assign){
        assert(sz(assign)==m);
        reverse(range(assign));
        rep(i,m) sum[i+1]=assign[i];
        rep1(i,m) sum[i]+=sum[i-1];
        int idx=0;
        auto calc1=[&](int u,int v){
            return sumr[u]+sum[v]+(n-u)*(m-v);
        };
        auto calc2=[&](int u,int v){
            return suml[u]+sum[v]+(n-u)*(m-v);
        };
        for (int i=n;i>-1;--i){
            while (idx<m&&calc1(i,idx)>calc1(i,idx+1)) idx++;
            if (calc1(i,idx)<t) return 0;
        }
        idx=0;
        for (int i=n;i>-1;--i){
            while (idx<m&&calc2(i,idx)>calc2(i,idx+1)) idx++;
            if (calc2(i,idx)<suml[n]) return 0;
        }
        return 1;
    };
    vi res;
    res.clear();
    int l=0, r=m, mxh;
    auto check=[&](int eq)->int{
        int ll=0,rr=n;
        while (ll<rr){
            int md=(ll+rr)>>1;
            int ss=eq*md;   
            for (int i=eq+1;i<=m;++i){
                ss+=min(rs[i],md);
            }
            if (ss<t) ll=md+1;
            else rr=md;
        }
        int nes=max(ll,ls[1]);
        int le=nes-1,ri=rs[eq]; 
        if (nes>ri) return -1;
        while (le<ri){
            int md=(le+ri)>>1;
            int rem=t;
            vi assign;
            assign.resize(m,0);
            rep1(i,m) assign[i-1]=(i<=eq?md+1:ls[i]), rem-=assign[i-1];
            if (rem<0){
                ri=md;
                continue;
            }
            int prv=m;
            for (int i=m;i>eq;--i){
                if (i!=eq+1&&rs[i]==rs[i-1]&&ls[i]==ls[i-1]) continue;
                int overhead=min((rs[i]-ls[i])*(prv-i+1),rem);
                rem-=overhead;
                for (int j=prv-i,k=prv;k>=i;k--,j--) {
                    assign[k-1]+=overhead/(prv-i+1);
                    if (j<overhead%(prv-i+1)) assign[k-1]++;
                }
                prv=i-1;
            } 
            if (check_valid(assign)) le=md+1;
            else ri=md;
        }
        if (le<nes) return -1;
        return le;
    };
    while (l<r){
        int md=(l+r)>>1;
        if ((mxh=check(md+1))!=-1) l=md+1;
        else r=md;
    }
    if (l){
        mxh=check(l); cout<<l<<" "<<mxh;
    }
    else{
        cout<<"-1 -1";
    }
    return 0;
}

//AACAB
//ABACA
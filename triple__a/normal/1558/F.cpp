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
 
 
const int maxn=200007;
const int mod=998244353;
const double pi=3.1415926535;

int lz[maxn<<2],mx[maxn<<2],p[maxn];
int t,n,a[maxn];
bool vis[maxn];
void pushup(int num){
    mx[num]=max(mx[num<<1],mx[num<<1|1]);
}

void pushdown(int num){
    mx[num<<1]+=lz[num], lz[num<<1]+=lz[num], mx[num<<1|1]+=lz[num], lz[num<<1|1]+=lz[num], lz[num]=0;
}

void build(int num,int l,int r){
    lz[num]=mx[num]=0;
    if (l==r) return;
    int md=(l+r)>>1;
    build(num<<1,l,md);
    build(num<<1|1,md+1,r);
}

void update(int num,int l,int r,int L,int R,int w){
    if (L<=l&&r<=R){
        mx[num]+=w, lz[num]+=w;
        return;
    }
    pushdown(num);
    int md=(l+r)>>1;
    if (L<=md) update(num<<1,l,md,L,R,w);
    if (R>md) update(num<<1|1,md+1,r,L,R,w);
    pushup(num);
}

int query(int num,int l,int r,int L,int R){
    if (L<=l&&r<=R) return mx[num];
    pushdown(num);
    int md=(l+r)>>1,ans=-1e9;
    if (L<=md) ans=max(ans,query(num<<1,l,md,L,R));
    if (R>md) ans=max(ans,query(num<<1|1,md+1,r,L,R));
    pushup(num);
    return ans;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    while (_--){
        int ans=0;
        cin>>n;
        int all_zero=n,all_ones=n+1;
        rep1(i,n) cin>>a[i], p[a[i]]=i;
        rep1(i,n) vis[i]=0;
        build(1,1,n);
        for (int i=1;i<=n;++i) update(1,1,n,i,i,-i-(i&1));
        for (int i=n;i>1;--i){
            update(1,1,n,p[i],n,2);
            vis[p[i]]=1, all_zero=min(all_zero,p[i]);
            while (all_ones>0&&vis[all_ones-1]) all_ones--;
            if (all_zero<all_ones) ans=max(ans,query(1,1,n,all_zero,all_ones-1)+i-1);
            // cerr<<"fuck:"<<all_zero<<" "<<all_ones<<endl;
            // cerr<<i<<" "<<query(1,1,n,all_zero,all_ones-1)+i-1<<endl;
        }
        cout<<ans<<"\n";
    }        
    return 0;
}
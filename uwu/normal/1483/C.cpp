#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, MAXN=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll n, st[2*MAXN], lz[2*MAXN];
void push(int v, int l, int r){
    st[v]+=lz[v];
    if (l!=r) lz[lc]+=lz[v], lz[rc]+=lz[v];
    lz[v]=0;
}
void upd(int ql, int qr, ll qv, int v=1, int l=0, int r=n){
    push(v,l,r);
    if (l>qr||r<ql) return;
    if (l>=ql&&r<=qr){ lz[v]+=qv, push(v,l,r); return; }
    upd(ql,qr,qv,lc,l,mid), upd(ql,qr,qv,rc,mid+1,r);
    st[v]=max(st[lc],st[rc]);
}

ll qry(int l, int r){
    upd(l,r,inf);
    ll ret=st[1]-inf;
    upd(l,r,-inf);
    return ret;
}

struct Fenwick{
    int a[MAXN];
    void upd(int i, int v){ for (;i<MAXN;i+=i&-i) a[i]=max(a[i],v); }
    int qry(int i){
        int ret=0;
        for (;i;i-=i&-i) ret=max(ret,a[i]);
        return ret;
    }
} bit;

ll h[MAXN], b[MAXN], dp[MAXN], psa[MAXN];

ll sum(int l, int r){ return psa[r]-psa[l-1]; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> h[i];
    for (int i=1;i<=n;++i) cin >> b[i];
    for (int i=1;i<=n;++i) psa[i]=psa[i-1]+b[i];
    dp[0]=0;
    for (int i=1;i<=n;++i){
        int l=bit.qry(h[i]); bit.upd(h[i],i);
        dp[i]=qry(l,i-1)+b[i];
        if (l!=0) dp[i]=max(dp[i],dp[l]);
        upd(i,i,dp[i]);
    }
    cout << dp[n] << '\n';
}
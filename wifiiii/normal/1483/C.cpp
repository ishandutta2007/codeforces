#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5+5;

ll mx[maxn<<2];
void update(int p,ll v,int l,int r,int rt) {
    if(l==r) {
        mx[rt]=v;
        return;
    }
    int m = (l + r) >> 1;
    if(m >= p) update(p,v,l,m,rt<<1);
    else update(p,v,m+1,r,rt<<1|1);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
ll query(int L,int R,int l,int r,int rt) {
    if(L <= l && r <= R) return mx[rt];
    int m = (l + r) >> 1;
    ll ret = -1e18;
    if(m >= L) ret = max(ret, query(L,R,l,m,rt<<1));
    if(m < R) ret = max(ret, query(L,R,m+1,r,rt<<1|1));
    return ret;
}
int h[maxn],a[maxn],stk[maxn],tp=0,l[maxn];
ll dp[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(mx,-0x3f,sizeof(mx));
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>h[i];
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) {
        while(tp && h[stk[tp]]>h[i]) --tp;
        if(tp) l[i]=stk[tp];
        else l[i]=0;
        stk[++tp]=i;
    }
    update(0,0,0,n,1);
    for(int i=1;i<=n;++i) {
        dp[i]=a[i]+query(l[i],i-1,0,n,1);
        if(l[i]) dp[i]=max(dp[i],dp[l[i]]);
        update(i,dp[i],0,n,1);
    }
    cout<<dp[n]<<'\n';
}
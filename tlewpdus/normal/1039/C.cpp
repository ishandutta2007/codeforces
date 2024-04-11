#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;
ll k, ans;
int par[500100];
ll key[500100];
ll po[500100];
ll MOD = 1e9+7;
pii edg[500100];
int fin(int a) {
    return par[a] = (par[a]==a?a:fin(par[a]));
}
int c;
void uni(int a, int b) {
    a = fin(a), b = fin(b);
    if (a==b) return;
    c--;
    par[a] = b;
}
ll val(pii a) {
    return key[a.first]^key[a.second];
}
int main() {
    scanf("%d%d%lld",&n,&m,&k);
    int i;
    po[0] = 1;
    for (i=1;i<=n;i++) po[i] = po[i-1]*2%MOD;
    for (i=0;i<n;i++) scanf("%lld",&key[i]);
    for (i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        edg[i] = pii(a,b);
    }
    for (i=0;i<n;i++) par[i] = i;
    sort(edg,edg+m,[](pii a, pii b){return (key[a.first]^key[a.second])<(key[b.first]^key[b.second]);});
    int p = 0, rp; ll t = 0;
    c = n;
    for (i=0;i<m;i++) {
        if (i==m-1||val(edg[i])!=val(edg[i+1])) {
            rp = p;t++;
            for (;p<=i;p++) {
                uni(edg[p].first,edg[p].second);
            }
            ans = (ans+po[c])%MOD;
            for (p=rp;p<=i;p++) {
                par[edg[p].first]=edg[p].first;
                par[edg[p].second]=edg[p].second;
            }
            c=n;
        }
    }
    printf("%lld\n",(ans+((1LL<<k)-t)%MOD*po[n]%MOD)%MOD);

    return 0;
}
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353 ;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll po(ll a, ll n) {
    if (!n) return 1;
    ll t = po(a,n/2);
    return t*t%MOD*(n%2?a:1)%MOD;
}

int n, q;
ll cur;
ll inv100 = po(100,MOD-2);
ll ppsum[200100];
ll pgob[200100];
ll p[200100];
set<int> lis;

ll calc(int s, int e) {
    return (ppsum[e-1]-(s>=2?ppsum[s-2]:0))*po(pgob[e],MOD-2)%MOD;
}

void upd(int idx){
    if (lis.find(idx)==lis.end()) {
        int v = *lis.lower_bound(idx);
        int w = *--lis.lower_bound(idx);
        cur -= calc(w,v-1);
        cur += calc(w,idx-1);
        cur += calc(idx,v-1);
        lis.insert(idx);
    }
    else {
        lis.erase(idx);
        int v = *lis.lower_bound(idx);
        int w = *--lis.lower_bound(idx);
        cur += calc(w,v-1);
        cur -= calc(w,idx-1);
        cur -= calc(idx,v-1);
    }
    cur=(cur%MOD+MOD)%MOD;
}

int main() {
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) {
        scanf("%lld",&p[i]);
        p[i]=p[i]*inv100%MOD;
    }
    lis.insert(1);
    lis.insert(n+1);
    p[0] = 1;
    pgob[0] = 1;
    ppsum[0] = 1;
    for (int i=1;i<=n;i++) {
        pgob[i]=pgob[i-1]*p[i]%MOD;
        ppsum[i]=(ppsum[i-1]+pgob[i])%MOD;
    }
    cur = ppsum[n-1]*po(pgob[n],MOD-2)%MOD;
    for (int i=0;i<q;i++) {
        int u;
        scanf("%d",&u);
        upd(u);
        printf("%lld\n",cur);
    }

	return 0;
}
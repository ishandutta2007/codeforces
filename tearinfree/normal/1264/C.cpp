#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli MOD = 998244353;

lli power(lli a,lli p) {
    lli ret=1;
    while(p) {
        if(p&1) ret = ret*a%MOD;
        p>>=1;
        a=a*a%MOD;
    }
    return ret;
}
lli inv(lli a) { return power(a, MOD-2); }

int n,q;
lli p[200001],s[200001],t[200001];

lli S(int idx) {
    if(idx==0) return 1;

    lli &ret=s[idx];
    if(ret!=-1) return ret;
    return ret=S(idx-1)*p[idx]%MOD;
}
lli T(int idx) {
    if(idx==-1) return 0;
    else if(idx==0) return 1;
    
    lli &ret=t[idx];
    if(ret!=-1) return ret;
    return ret = (T(idx-1) + S(idx))%MOD;
}

lli get(int a,int b) {
    return (T(b-1)-T(a-2)+MOD)%MOD*inv(S(b))%MOD;
}

int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",p+i), p[i] = p[i] * inv(100)%MOD;

    memset(s, -1,sizeof(s));
    memset(t, -1,sizeof(t));

    set<int> tr;
    lli ans=get(1,n);
    while(q--) {
        int idx;
        scanf("%d",&idx);

        int l=1,r=n+1,f=0;
        if(tr.find(idx)!=tr.end()) {
            f=1; tr.erase(idx);
        }
        auto it = tr.lower_bound(idx);
        if(it!=tr.end()) r = *it;
        if(it!=tr.begin()) l = *prev(it);

        if(!f) {
            ans = (ans - get(l, r-1) + MOD)%MOD;
            ans = (ans + get(l, idx-1) + MOD)%MOD;
            ans = (ans + get(idx, r-1) + MOD)%MOD;
            tr.insert(idx);
        } else {
            ans = (ans + get(l, r-1) + MOD)%MOD;
            ans = (ans - get(l, idx-1) + MOD)%MOD;
            ans = (ans - get(idx, r-1) + MOD)%MOD;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
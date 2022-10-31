#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,k,arr[100000],vis[100100];

const int INF = 1e9;
int mul(int a,int b) {
    return min(1ll*a*b, 1ll*INF);
}
int power(int a,int p) {
    int ret = 1;
    while(p) {
        if(p&1) ret = mul(ret, a);
        a = mul(a, a);
        p>>=1;
    }
    return ret;
}

int main() {
    for(int i=2;i<=100000;i++) if(!vis[i]) {
        vis[i] = i;
        for(lli j=1ll*i*i;j<=100000;j+=i) if(!vis[j]) vis[j] = i;
    }
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    map<int, int> tr, rev;
    for(int i=0;i<n;i++) {
        int val = arr[i];
        int a1=1,a2=1;
        while(val>1) {
            int div = vis[val], cnt=0;
            while(val % div == 0) {
                val /= div;
                cnt++;
            }
            cnt %= k;
            if(cnt) {
                a1 = mul(a1, power(div, cnt));
                a2 = mul(a2, power(div, k-cnt));
            }
        }
        tr[a1]+=1;
        rev[a1]=a2;
    }
    lli ans = 0;
    for(auto &it:tr) {
        if(it.fi == INF) continue;
        int rv = rev[it.fi];
        if(rv < INF && tr.count(rv)) {
            if(it.fi == rv) {
                ans += 1ll*it.se*(it.se-1) / 2;
            } else if(it.fi < rv) {
                ans += 1ll*it.se*tr[rv];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
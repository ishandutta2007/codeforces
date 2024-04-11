#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=1e5+1;

ll fact[MAXN], inv[MAXN];
ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ret;
}
ll choose(int n, int k){ return fact[n]*inv[k]%mod*inv[n-k]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0]=inv[0]=1;
    for (int i=1;i<MAXN;++i) fact[i]=fact[i-1]*i%mod;
    for (int i=1;i<MAXN;++i) inv[i]=fpow(fact[i],mod-2);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int o=0, e=0, cnt=0;
        for (int i=1;i<=n;++i){
            char s; cin >> s;
            if (s=='0'){
                if (cnt==1) o++;
                cnt=0;
            }
            else{
                cnt++;
                if (cnt==2) e++, cnt=0;
            }
        }
        if (cnt==1) o++;
        cout << choose(n-o-e,e) << '\n';
    }
}
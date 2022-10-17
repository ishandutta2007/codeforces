#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 998244353;
VI fact, inv;

int modpow(int a, int e){
        int ret = 1;
        while(e > 0){
                if(e&1) ret = (1ll*ret*a)%MOD;
                a = (1ll*a*a)%MOD;
                e>>=1;
        }
        return ret;
}

int binco(int n, int k){
        if(k < 0 ||  k > n) return 0;
        auto xd = (1ll*fact[n]*inv[k])%MOD;
        return (1ll*xd*inv[n-k])%MOD;
}

int main(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);

        fact.push_back(1);
        inv.push_back(1);
        REP(i, 1, 300005) fact.push_back(1ll*fact.back()*i%MOD), inv.push_back(modpow(fact.back(), MOD-2));

        int n;
        std::cin >> n;
        VI A(n*2);
        FOR(i, 2*n) std::cin >> A[i];
        std::sort(A.begin(), A.end());

        int ile = binco(2*n, n);
        int ans = 0;
        FOR(i, n){
                ans = (ans + 1ll*ile*(MOD-A[i]))%MOD;
        }
        REP(i, n, 2*n){
                ans = (ans + 1ll*ile*A[i])%MOD;
        }
        std::cout << ans << "\n";

        return 0;
}
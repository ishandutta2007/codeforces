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

int main(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);

        int t;
        std::cin >>t;
        while(t--){
                ll p, q;
                std::cin >> p >> q;
                if(p%q != 0) std::cout << p << "\n";
                else{
                        ll i = 2;
                        std::vector<PR<ll, ll> > A;
                        ll orig_q = q;
                        while(q > 1 && i*i <= orig_q){
                                int cnt = 0;
                                while(q%i == 0) cnt++, q /= i;
                                if(cnt > 0){
                                        A.push_back(MP(i, cnt));
                                }
                                i++;
                        }
                        if(q > 1) A.push_back(MP(q, 1));

                        ll best = -1;
                        TRAV(pr, A){
                                int ile = 0;
                                ll x = p;
                                while(x%pr.X == 0) x /= pr.X, ile++;
                                assert(ile >= pr.Y);
                                int od = ile-pr.Y+1;
                                x = p;
                                FOR(j, od) x /= pr.X;
                                best = std::max(best, x);
                        }

                                assert(best > -1);
                        std::cout << best << "\n";
                }
        }

        return 0;
}
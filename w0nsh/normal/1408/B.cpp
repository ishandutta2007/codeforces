#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
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
    std::cin >> t;
    while(t--){
        int n, k;
        std::cin >> n >> k;
        VI A(n);
        FOR(i, n) std::cin >> A[i];

        if(k == 1){
            if(A[0] != A.back()){
                std::cout << -1 << "\n";
            }else{
                std::cout << 1 << "\n";
            }
            continue;
        }

        int dif = 1;
        FOR(i, n-1) if(A[i] != A[i+1]) dif++;
        int need = dif;
        int ans = 1;
        need -= k;
        if(need > 0){
           ans += (need+(k-2))/(k-1);    
        }
        std::cout << ans << "\n";

    }

	return 0;
}
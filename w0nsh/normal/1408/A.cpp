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
        int n;
        std::cin >> n;
        std::vector<VI> A(3, VI(n));
        FOR(i, 3){
            FOR(j, n) std::cin >> A[i][j];
        }
        VI seq(n, -1);
        seq[0] = A[0][0];
        REP(i, 1, n-1){
            FOR(j, 3){
                if(seq[i-1] != A[j][i]){
                    seq[i] = A[j][i];
                    break;
                }
            }
            assert(seq[i] != -1);
        }
        FOR(j, 3){
            seq[n-1] = A[j][n-1];
            if(seq[n-1] != seq[0] && seq[n-1] != seq[n-2]) break;
            seq[n-1] = -1;
        }
        assert(seq[n-1] != -1);
        FOR(i, n) std::cout << seq[i] << " ";
        std::cout << "\n";
    }

	return 0;
}
#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int xr[5005][5005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	VI B(n);
	FOR(i, n) FOR(j, n) xr[i][j] = -1;
	FOR(i, 2*n-1){
		std::cout << "? " << (i+1)/2 << " " << i/2  << std::endl;
		std::cin >> xr[(i+1)/2][i/2];
	}
	int cnt = 0;
	VI pos;
	FOR(fs, n){
		A[0] = fs;
		REP(i, 1, n){
			A[i] = (A[i-1]^xr[i-1][i-1]^xr[i][i-1]);
		}
		std::fill(B.begin(), B.end(), -1);
		bool bad = false;
		FOR(i, n){
			if(A[i] >= n || A[i] < 0){
				bad = true;
				break;
			}
			if(B[A[i]] != -1){
				bad = true;
				break;
			}
			B[A[i]] = i;
		}
		if(bad) continue;
		FOR(i, 2*n-1){
			if((A[(i+1)/2]^B[i/2]) != xr[(i+1)/2][i/2]){
				bad = true;
				break;
			}
		}
		if(!bad){
			if(pos.empty()) pos = A;
			cnt++;
		}
	}
	std::cout << "!" << std::endl;
	std::cout << cnt << std::endl;
	TRAV(i, pos) std::cout << i << " ";
	std::cout << std::endl;


	return 0;
}
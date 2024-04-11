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

int tab[1005][1005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	FOR(i, n){
		FOR(j, n){
			std::cin >> tab[i][j];
		}
	}
	std::vector<ll> A(n);
	FOR(a, n){
		int b = (a+1)%n;
		int c = (b+1)%n;
		A[b] = 1ll*tab[a][b]*tab[b][c]/tab[a][c];
		A[b] = std::round(std::sqrt(A[b]));
	}
	FOR(i, n) std::cout << A[i] << " ";
	return 0;
}
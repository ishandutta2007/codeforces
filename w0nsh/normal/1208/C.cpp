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
VI ar = {8, 9, 1, 13,
3, 12, 7, 5,
0, 2, 4, 11,
6, 10, 15, 14};
	int n;
	std::cin >> n;
	int kt = 0;
	FOR(i, n/4){
		FOR(j, n/4){
			FOR(k, 4){
				FOR(l, 4){
					tab[i*4+k][j*4+l] = ar[k*4+l]+kt;
				}
			}
			kt += 16;
		}
	}
	FOR(i, n){
		FOR(j, n){
			std::cout << tab[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 0;

}
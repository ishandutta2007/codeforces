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

int n;
int cnt[1000];
int mat[25][25];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n*n){
		int a;
		std::cin >> a;
		a--;
		cnt[a]++;
	}
	int cur = 0;
	FOR(i, n/2) FOR(j, n/2){
		while(cur < 1000 && cnt[cur] < 4) cur++;
		if(cur == 1000){
			std::cout << "NO\n";
			return 0;
		}
		cnt[cur] -= 4;
		mat[i][j] = mat[n-i-1][j] = mat[i][n-j-1] = mat[n-i-1][n-j-1] = cur;
	}
	if(n % 2 == 1){
		cur = 0;
		FOR(i, n/2){
			while(cur < 1000 && cnt[cur] < 2) cur++;
			if(cur == 1000){
				std::cout << "NO\n";
				return 0;
			}
			cnt[cur] -= 2;
			mat[n/2][i] = mat[n/2][n-i-1] = cur;
		}
		FOR(i, n/2){
			while(cur < 1000 && cnt[cur] < 2) cur++;
			if(cur == 1000){
				std::cout << "NO\n";
				return 0;
			}
			cnt[cur] -= 2;
			mat[i][n/2] = mat[n-i-1][n/2] = cur;
		}
		cur = 0;
		while(cur < 1000 && cnt[cur] < 1) cur++;
		mat[n/2][n/2] = cur;
	}
	std::cout << "YES\n";
	FOR(i, n){
		FOR(j, n) std::cout << mat[i][j]+1 << " ";
		std::cout << "\n";
	}
	return 0;
}
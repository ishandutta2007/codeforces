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

const int MOD = 1000000007;

int n, m;
int dp[2005][2005][2];
int tak[2005][2005][2];
int pref[2005][2005][2];
char tab[2005][2005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	if(n == 1 && m == 1){
		std::cout << 1;
		return 0;
	}
	REP(i, 1, n+1) REP(j, 1, m+1) std::cin >> tab[i][j];
	pref[1][1][0] = pref[1][1][1] = dp[1][1][0] = dp[1][1][1] = 1;
	for(int i = n; i >= 0; --i){
		for(int j = m; j >= 0; --j){
			tak[i][j][0] = tak[i+1][j][0]+(tab[i][j] == 'R' ? 1 : 0);
			tak[i][j][1] = tak[i][j+1][1]+(tab[i][j] == 'R' ? 1 : 0);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(i == 1 && j == 1) continue;
			int left = 1;
			int right = i+1;
			while(left < right){
				int mid = (left+right)/2;
				//std::cout << "mid " << mid << ", " << " tak " << tak[mid][j][0] << std::endl;
				if(tak[mid][j][0] >= (n-i+1)){
					left = mid+1;
				}else{
					right = mid;
				}
			}
			left--;
			//std::cout << i << ", " << j << " = " << left << std::endl;
			dp[i][j][0] = (pref[i-1][j][0]-pref[std::max(0, left-1)][j][0]+MOD)%MOD;

			left = 1;
			right = j+1;
			while(left < right){
				int mid = (left+right)/2;
				if(tak[i][mid][1] >= (m-j+1)){
					left = mid+1;
				}else{
					right = mid;
				}
			}
			left--;
			
			//std::cout << i << ", " << j << " = " << left << std::endl;
			//std::cout << "wiec " << pref[i][j-1][1] << " - " << pref[i][std::max(0, left-1)][1] << std::endl;
			dp[i][j][1] = (pref[i][j-1][1]-pref[i][std::max(0, left-1)][1]+MOD)%MOD;


			pref[i][j][1] = (pref[i][j-1][1]+dp[i][j][0])%MOD;
			pref[i][j][0] = (pref[i-1][j][0]+dp[i][j][1])%MOD;
		}
	}/*
	FOR(i, n+1){
		FOR(j, m+1){
			std::cout << tak[i][j][0] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "==dp====\n";
	FOR(i, n+1){
		FOR(j, m+1){
			std::cout << dp[i][j][0] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "====pref===\n";
	FOR(i, n+1){
		FOR(j, m+1){
			std::cout << pref[i][j][0] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "LEFT====dp===\n";
	FOR(i, n+1){
		FOR(j, m+1){
			std::cout << dp[i][j][1] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "==pref=====\n";
	FOR(i, n+1){
		FOR(j, m+1){
			std::cout << pref[i][j][1] << " ";
		}
		std::cout << "\n";
	}
	*/
	std::cout << (dp[n][m][0]+dp[n][m][1])%MOD;
	return 0;
}
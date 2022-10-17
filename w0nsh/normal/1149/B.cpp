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

const int INF = 1000000666;
int n, q;
int next[26][100005];
int dp[255][255][255];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	std::string str;
	std::cin >> str;
	FOR(c, 26){
		next[c][n] = INF;
		for(int i = n-1; i >= 0; --i){
			if(str[i]-'a' == c) next[c][i] = i; 
			else next[c][i] = next[c][i+1];
		}
	}
	// dp[i][j][k] - jak dlugi prefix zeby zmiescic prefix A_i, B_j, C_k
	FOR(i, 255) FOR(j, 255) FOR(k, 255) dp[i][j][k] = INF;
	dp[0][0][0] = -1;
	std::string A[3];
	FOR(_, q){
		char what;
		std::cin >> what;
		if(what == '-'){
			int ind;
			std::cin >> ind;
			A[--ind].pop_back();
		}else{
			int ind;
			char ch;
			std::cin >> ind >> ch;
			A[--ind].push_back(ch);
			int place = SZ(A[ind]);
			if(ind == 2){
				FOR(i, SZ(A[0])+1) FOR(j, SZ(A[1])+1){
					dp[i][j][place] = (dp[i][j][place-1] == INF ? INF : next[A[2][place-1]-'a'][dp[i][j][place-1]+1]);
					if(i > 0) dp[i][j][place] = std::min(dp[i][j][place],
											(dp[i-1][j][place] == INF ? INF : next[A[0][i-1]-'a'][dp[i-1][j][place]+1]));
					if(j > 0) dp[i][j][place] = std::min(dp[i][j][place],
											(dp[i][j-1][place] == INF ? INF : next[A[1][j-1]-'a'][dp[i][j-1][place]+1]));
				}
			}else if(ind == 1){
				FOR(i, SZ(A[0])+1) FOR(j, SZ(A[2])+1){
					dp[i][place][j] = (dp[i][place-1][j] == INF ? INF : next[A[1][place-1]-'a'][dp[i][place-1][j]+1]);
					if(i > 0) dp[i][place][j] = std::min(dp[i][place][j],
											(dp[i-1][place][j] == INF ? INF : next[A[0][i-1]-'a'][dp[i-1][place][j]+1]));
					if(j > 0) dp[i][place][j] = std::min(dp[i][place][j],
											(dp[i][place][j-1] == INF ? INF : next[A[2][j-1]-'a'][dp[i][place][j-1]+1]));
				}
			}else{
				FOR(i, SZ(A[1])+1) FOR(j, SZ(A[2])+1){
					dp[place][i][j] = (dp[place-1][i][j] == INF ? INF : next[A[0][place-1]-'a'][dp[place-1][i][j]+1]);
					if(i > 0) dp[place][i][j] = std::min(dp[place][i][j],
											(dp[place][i-1][j] == INF ? INF : next[A[1][i-1]-'a'][dp[place][i-1][j]+1]));
					if(j > 0) dp[place][i][j] = std::min(dp[place][i][j],
											(dp[place][i][j-1] == INF ? INF : next[A[2][j-1]-'a'][dp[place][i][j-1]+1]));
				}
			}
		}
		if(dp[SZ(A[0])][SZ(A[1])][SZ(A[2])] < INF) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}
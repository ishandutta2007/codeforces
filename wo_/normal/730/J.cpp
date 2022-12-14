#include<cstdio>
#include<algorithm>

using namespace std;

const int MA = 105;

int N;
int as[110];
int bs[110];

int all;

int dp[MA][MA][MA * MA];

void solve(){
	all = 0;
	for(int i = 0; i < N; ++i) all += as[i];
	
	for(int i = 0; i < MA; ++i){
		for(int j = 0; j < MA; ++j){
			for(int k = 0; k < MA * MA; ++k){
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][0][0] = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j <= i; ++j){
			for(int k = 0; k < MA * MA; ++k){
				if(dp[i][j][k] == -1) continue;
				
				//not use
				dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
				
				//use
				if(k + bs[i] < MA * MA){
					dp[i + 1][j + 1][k + bs[i]] = max(dp[i + 1][j + 1][k + bs[i]], dp[i][j][k] + as[i]);
				}
			}
		}
	}
	
	int best_k = MA, best_t = MA * MA;
	for(int j = 1; j <= N; ++j){
		for(int k = all; k < MA * MA; ++k){
			if(dp[N][j][k] != -1){
				best_t = min(best_t, all - dp[N][j][k]);
			}
		}
		if(best_t != MA * MA){
			best_k = j;
			break;
		}
	}
	printf("%d %d\n", best_k, best_t);
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", as + i);
	}
	for(int i = 0; i < N; ++i){
		scanf("%d", bs + i);
	}
}

int main(){
	input();
	solve();
	return 0;
}
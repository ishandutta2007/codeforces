#include<bits/stdc++.h>

const int N = 2;
const int M = 16;

int ans[N][N][N];
int now[N][N];
int n;

void solve(int op1, int op2, int op3){
	int left, right;
	left = 1, right = ans[op1][op2][op3];
	if (!op3){
		std::swap(left, right);
		right = ans[op1][op2][1];
	}
	while (left < right){
		int mid = op3 ? left + right >> 1 : left + right + 1 >> 1;
		ans[op1][op2][op3] = mid;
		printf("?");
		for (int j = 0; j < N; ++ j){
			for (int i = 0; i < N; ++ i){
				printf(" %d", ans[op1][i][j]);
			}
		}
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (op1){
			bool flag = true;
			for (int i = 0; i < N; ++ i){
				for (int j = 0; j < N; ++ j){
					if (j){
						if (ans[op1][i][j] < ans[0][i][j]){
							flag = false;
						}
					}
					else{
						if (ans[op1][i][j] > ans[0][i][j]){
							flag = false;
						}
					}
				}
			}
			if (flag){
				-- x;
			}
		}
		if (op3){
			if (x){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
		else{
			if (x){
				left = mid;
			}
			else{
				right = mid - 1;
			}
		}
	}
	ans[op1][op2][op3] = left;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			for (int k = N - 1; ~k; -- k){
				ans[i][j][k] = k ? n : 1;
			}
		}
	}
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			for (int k = N - 1; ~k; -- k){
				solve(i, j, k);
			}
		}
	}
	printf("!");
	for (int i = 0; i < N; ++ i){
		for (int k = 0; k < N; ++ k){
			for (int j = 0; j < N; ++ j){
				printf(" %d", ans[i][j][k]);
			}
		}
	}
	printf("\n");
	fflush(stdout);
	return 0;
}
#include<bits/stdc++.h>

const int N = 1010;

int n;

int cord[N][5];
bool good[N];

int dot(int sit0, int sit1, int sit2){
	int ret = 0;
	for (int i = 0; i < 5; ++ i){
		ret += (cord[sit1][i] - cord[sit0][i]) * (cord[sit2][i] - cord[sit0][i]);
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < 5; ++ j){
			scanf("%d", &cord[i][j]);
		}
	}
	if (n >= 100){
		return printf("0\n"), 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++ i){
		good[i] = true;
		for (int j = 0; j < n; ++ j){
			if (j == i) continue;
			for (int k = j + 1; k < n; ++ k){
				if (k == i) continue;
				if (dot(i, j, k) > 0){
					good[i] = false;
					break;
				}
			}
		}
		cnt += good[i];
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; ++ i){
		if (good[i]){
			printf("%d\n", i + 1);
		}
	}
	return 0;
}
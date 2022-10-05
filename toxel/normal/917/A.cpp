#include<bits/stdc++.h>

const int N = 5010;

bool vis1[N][N], vis2[N][N];
char s[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++ i){
		int left = 0, right = 0;
		for (int j = i; j < n; ++ j){
			left += s[j] == '?' || s[j] == '(';
			right += s[j] == ')';
			if (left < right){
				break;
			}
			if (i + j & 1){
				vis1[i][j] = true;
			}
		}
	}
	for (int i = n - 1; i >= 0; -- i){
		int left = 0, right = 0;
		for (int j = i; j >= 0; -- j){
			left += s[j] == '(';
			right += s[j] == '?' || s[j] == ')';
			if (right < left){
				break;
			}
			if (i + j & 1){
				vis2[j][i] = true;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			sum += vis1[i][j] && vis2[i][j];
		}
	}
	printf("%d\n", sum);
	return 0;
}
#include<bits/stdc++.h>

const int N = 100010;

int pre[2][N];
char s[N];

int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++ i){
		pre[0][i] = pre[0][i - 1] + (s[i] >= 'a' && s[i] <= 'z');
		pre[1][i] = pre[1][i - 1] + (s[i] >= 'A' && s[i] <= 'Z');
	}
	int min = INT_MAX;
	for (int i = 0; i <= n; ++ i){
		min = std::min(min, pre[0][i] + pre[1][n] - pre[1][i]);
	}
	return printf("%d\n", min), 0;
}
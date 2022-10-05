#include<bits/stdc++.h>

const int N = 5010;

int prea[N], preb[N];
char s[N];

int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++ i){
		prea[i] = prea[i - 1] + (s[i] == 'a');
		preb[i] = preb[i - 1] + (s[i] == 'b');
	}
	int min = INT_MAX;
	for (int i = 1; i <= n + 1; ++ i){
		for (int j = i; j <= n + 1; ++ j){
			min = std::min(min, preb[i - 1] + prea[j - 1] - prea[i - 1] + preb[n] - preb[j - 1]);
		}
	}
	return printf("%d\n", n - min), 0;
}
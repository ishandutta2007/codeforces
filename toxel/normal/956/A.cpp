#include<bits/stdc++.h>

const int N = 60;

std::bitset <N> set[N];

char s[N][N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++ j){
			if (s[i][j] == '#') set[i].set(j);
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < i; ++ j){
			if (set[i] != set[j]){
				if ((set[i] & set[j]).any()){
					puts("No");
					return 0;
				}
			}
		}
	}
	puts("Yes");
	return 0;	
}
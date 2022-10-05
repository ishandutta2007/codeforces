#include<bits/stdc++.h>

const int N = 110;

char s[N][10], pass[10];

int main(){
	scanf("%s", pass);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; ++ i){
		if (!strcmp(s[i], pass)){
			return printf("YES\n"), 0;
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			if (pass[0] == s[i][1] && pass[1] == s[j][0]){
				return printf("YES\n"), 0;
			}
		}
	}
	return printf("NO\n"), 0;
}
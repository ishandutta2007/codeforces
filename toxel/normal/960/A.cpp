#include<bits/stdc++.h>

const int N = 5010;

char s[N];
int cnt[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n - 1; ++ i){
		if (s[i] > s[i + 1]){
			puts("NO");
			return 0;
		}
	}
	for (int i = 0; i < n; ++ i){
		++ cnt[s[i]];
	}
	if (!cnt['a'] || !cnt['b']){
		puts("NO");
		return 0;
	}
	if (cnt['c'] != cnt['a'] && cnt['c'] != cnt['b']){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}
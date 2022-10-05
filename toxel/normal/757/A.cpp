#include<bits/stdc++.h>

const int N = 100010;

char s[N];
int cnt[N];

int main(){
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		++ cnt[s[i]];
	}
	int min = INT_MAX;
	min = std::min(min, cnt['B']);
	min = std::min(min, cnt['u'] >> 1);
	min = std::min(min, cnt['l']);
	min = std::min(min, cnt['b']);
	min = std::min(min, cnt['a'] >> 1);
	min = std::min(min, cnt['s']);
	min = std::min(min, cnt['r']);
	printf("%d\n", min);
	return 0;
}
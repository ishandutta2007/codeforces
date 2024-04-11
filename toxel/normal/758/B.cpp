#include<bits/stdc++.h>

const int N = 210;

int cnt[N], a[N];
char s[N];

int main(){
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		if (s[i] != '!'){
			a[s[i]] = i % 4;
		}
	}
	for (int i = 0; i < len; ++ i){
		if (s[i] == '!'){
			++ cnt[i % 4];
		}	
	}
	printf("%d %d %d %d\n", cnt[a['R']], cnt[a['B']], cnt[a['Y']], cnt[a['G']]);
	return 0;
}
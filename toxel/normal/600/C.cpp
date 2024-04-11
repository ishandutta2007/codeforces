#include<bits/stdc++.h>

const int N = 200010;

char s[N];
int cnt[N];

int main(){
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		++ cnt[s[i] - 'a'];
	}
	for (int i = 0, j = 25; ; ){
		while (i < 26 && !(cnt[i] & 1)){
			++ i;
		}
		while (j >= 0 && !(cnt[j] & 1)){
			-- j;
		}
		if (i >= j) break;
		++ cnt[i], -- cnt[j];
	}
	for (int i = 0; i < 26; ++ i){
		for (int j = 0; j < cnt[i] >> 1; ++ j){
			putchar(i + 'a');
		}
	}
	for (int i = 0; i < 26; ++ i){
		if (cnt[i] & 1){
			putchar(i + 'a');
		}
	}
	for (int i = 25; i >= 0; -- i){
		for (int j = 0; j < cnt[i] >> 1; ++ j){
			putchar(i + 'a');
		}
	}
	return 0;
}
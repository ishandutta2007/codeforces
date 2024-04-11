#include<bits/stdc++.h>

const int N = 40;

char s[N];

bool check(){
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		if (s[i] != s[len - i - 1]){
			return false;
		}
	}
	return true;
}

int main(){
	int x;
	scanf("%d", &x);
	int cnt = 0;
	for ( ; x; x /= 10){
		s[cnt ++] = x % 10 + '0';
	}
	for (int i = cnt; i < N; ++ i){
		if (check()){
			return printf("YES\n"), 0;
		}
		s[i] = '0';
	}
	return printf("NO\n"), 0;
}
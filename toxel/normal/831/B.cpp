#include<bits/stdc++.h>

const int N = 1010;
const int M = 26;

int inv[M];
char a[N], b[N], s[N];

int main(){
	scanf("%s%s%s", a, b, s);
	for (int i = 0; i < M; ++ i){
		inv[a[i] - 'a'] = b[i] - 'a';
	}
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		if (s[i] >= '0' && s[i] <= '9'){
			putchar(s[i]);
		}
		else if (s[i] >= 'a' && s[i] <= 'z'){
			putchar('a' + inv[s[i] - 'a']);
		}
		else{
			putchar('A' + inv[s[i] - 'A']);
		}
	}
	return printf("\n"), 0;
}
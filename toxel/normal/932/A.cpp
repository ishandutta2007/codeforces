#include<bits/stdc++.h>

const int N = 1010;

char s[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++ i){
		putchar(s[i]);
	}
	for (int i = n - 1; i >= 0; -- i){
		putchar(s[i]);
	}
	putchar('\n');
	return 0;
}
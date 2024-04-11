#include<bits/stdc++.h>

const int N = 100010;
int n, a, b;
char s[N];

int main(){
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", s);
	return printf(s[a - 1] == s[b - 1] ? "0\n" : "1\n"), 0;
}
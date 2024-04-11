#include<bits/stdc++.h>

const int N = 100;

char home[N], s[N];
int n;

int main(){
	scanf("%d%s", &n, home);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s);
	}
	return printf(n & 1 ? "contest\n" : "home\n"), 0;
}
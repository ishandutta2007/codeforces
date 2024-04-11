#include<bits/stdc++.h>

const int N = 210;

char s[N];

int main(){
	int k, a, b;
	scanf("%d%d%d%s", &k, &a, &b, s);
	int len = strlen(s);
	if (a * k > len || b * k < len){
		puts("No solution");
		return 0;
	}
	int sit = 0;
	for (int i = 0; i < k; ++ i){
		int sz = len / k + (i < len % k);
		for (int j = sit; j < sit + sz; ++ j){
			putchar(s[j]);
		}
		putchar('\n');
		sit += sz;
	}
	return 0;
}
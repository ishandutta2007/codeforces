#include<bits/stdc++.h>

const int N = 110;
const int M = 26;

char s[N];

int main(){
	scanf("%s", s);
	int len = strlen(s), ans = 0, now = 0;
	for (int i = 0; i < len; ++ i){
		int x = std::abs(s[i] - 'a' - now);
		ans += std::min(x, M - x);
		now = s[i] - 'a';
	}
	return printf("%d\n", ans), 0;
}
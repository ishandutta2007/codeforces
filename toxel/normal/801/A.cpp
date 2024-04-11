#include<bits/stdc++.h>

const int N = 110;

char s[N];

int calc(){
	int len = strlen(s), cnt = 0;
	for (int i = 0; i < len - 1; ++ i){
		if (s[i] == 'V' && s[i + 1] == 'K'){
			++ cnt;
		}
	}
	return cnt;
}

int main(){
	scanf("%s", s);
	int len = strlen(s);
	int ans = calc();
	for (int i = 0; i < len; ++ i){
		s[i] = s[i] == 'V' ? 'K' : 'V';
		ans = std::max(ans, calc());
		s[i] = s[i] == 'V' ? 'K' : 'V';
	}
	return printf("%d\n", ans), 0;
}
#include<bits/stdc++.h>

const int N = 200010;

char s[N];
int moder;

int main(){
	scanf("%s%d", &s, &moder);
	int now = 0, mod = 1, len = strlen(s);
	for (int i = 0; i < len; ++ i){
		now = (now * 10 + s[i] - '0') % moder;
		if (i){
			mod = mod * 10 % moder;
		}
	}
	int min = INT_MAX;
	for (int i = 0; i < len; ++ i){
		if (s[i] != '0'){
			min = std::min(min, now);
		}
		now = (((now - (s[i] - '0') * mod) % moder + moder) * 10 + s[i] - '0') % moder;
	}
	return printf("%d\n", min), 0;
}
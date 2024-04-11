#include<bits/stdc++.h>

const int N = 1000010;
const int moder = 1e9 + 7;

char s[N];

int main(){
	scanf("%s", s);
	int len = strlen(s), cnt = 0, ans = 0;
	for (int i = len - 1; i >= 0; -- i){
		if (s[i] == 'b'){
			++ cnt;
		}
		else{
			ans = (ans + cnt) % moder;
			cnt = 2ll * cnt % moder;
		}
	}
	return printf("%d\n", ans), 0;
}
#include<bits/stdc++.h>

const int N = 100010;

char s[N];
int cnt[N];

int main(){
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		switch (s[i]){
			case 'L' : ++ cnt[0]; break;
			case 'R' : ++ cnt[1]; break;
			case 'U' : ++ cnt[2]; break;
			case 'D' : ++ cnt[3]; break;
		}
	}
	if (len & 1){
		return printf("-1\n"), 0;
	}
	int min = INT_MAX;
	for (int i = 0; i < N; ++ i){
		int x = (len >> 1) - i;
		if (x < 0){
			break;
		}
		min = std::min(std::abs(cnt[0] - i) + std::abs(cnt[1] - i) + std::abs(cnt[2] - x) + std::abs(cnt[3] - x) >> 1, min);
	}
	return printf("%d\n", min), 0;
}
#include<bits/stdc++.h>

int n, k;
const int N = 100010;

int s[N][5];
int cnt[N];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i){
		int type = 0;
		for (int j = 0; j < k; ++ j){
			scanf("%d", &s[i][j]);
			(type <<= 1) |= 1 ^ s[i][j];
		}
		++ cnt[type];
	}
	for (int i = 0; i < 1 << k; ++ i){
		for (int j = 0; j < 1 << k; ++ j){
			if (cnt[i] && cnt[j] && ((i | j) == (1 << k) - 1)){
				return printf("YES\n"), 0;
			}
		}
	}
	return printf("NO\n"), 0;
}
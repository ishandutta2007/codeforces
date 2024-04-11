#include<bits/stdc++.h>

const int N = 210;

char s[N];
int cnt[N];
int n;

int main(){
	scanf("%d%s", &n, s);
	s[n ++] = 'A';
	int pre = 0, ans = 0;;
	for (int i = 0; i < n; ++ i){
		if (s[i] >= 'A' && s[i] <= 'Z'){
			memset(cnt, 0, sizeof(cnt));
			for (int j = pre; j < i; ++ j){
				++ cnt[s[j]];
			}
			int tot = 0;
			for (int j = 0; j < N; ++ j){
				tot += cnt[j] > 0;
			}
			ans = std::max(ans, tot);
			pre = i + 1;
		}
	}
	return printf("%d\n", ans), 0;
}
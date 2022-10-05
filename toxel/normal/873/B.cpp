#include<bits/stdc++.h>

const int N = 100010;

int sit[N << 1];
int n;
char s[N];

int main(){
	memset(sit, -1, sizeof(sit));
	scanf("%d%s", &n, s);
	int now = N;
	sit[now] = 0;
	int ans = 0;
	for (int i = 0; i < n; ++ i){
		now += s[i] == '1' ? 1 : -1;
		if (~sit[now]){
			ans = std::max(ans, i + 1 - sit[now]);
		}
		else{
			sit[now] = i + 1;
		}
	}
	return printf("%d\n", ans), 0;
}
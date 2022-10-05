#include<bits/stdc++.h>
#define ll long long

const int N = 18;

int cnt[1 << N];
int t;
char s[N];

int main(){
	scanf("%d", &t);
	while (t --){
		scanf("%s", s);
		if (s[0] == '+' || s[0] == '-'){
			ll n;
			scanf("%I64d", &n);
			int x = 0;
			for (int i = 0; i < N; ++ i, n /= 10){
				x += (n % 10 & 1) << i;
			}
			s[0] == '+' ? ++ cnt[x] : -- cnt[x];
			continue;
		}
		scanf("%s", s);
		int x = 0, len = strlen(s);
		for (int i = len - 1; ~i; -- i){
			x += s[i] - '0' << len - 1 - i;
		}
		printf("%d\n", cnt[x]);
	}
	return 0;
}
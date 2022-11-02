#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

char S[N + 5]; int n; ll T;

int cnt[60];

int main() {
	scanf("%d%lld%s", &n, &T, S + 1);
	T -= (1ll << (S[n] - 'a')), T += (1ll << (S[n - 1] - 'a'));
	for(int i=1;i<=n-2;i++) {
		T += (1ll << (S[i] - 'a'));
		cnt[S[i] - 'a' + 1]++;
	}
	
	if( T < 0 ) {puts("No"); return 0;}
	else {
		for(int i=59;i>=0;i--) {
			ll p = (T >> i);
			T -= std::min(p, 1ll * cnt[i]) << i;
		}
		puts(T ? "No" : "Yes");
	}
}
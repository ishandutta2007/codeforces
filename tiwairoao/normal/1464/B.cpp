#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

char s[N + 5]; int n, m, x, y;

int cntp[2][N + 5], cnts[2][N + 5];

int main() {
	scanf("%s%d%d", s + 1, &x, &y), n = strlen(s + 1);
	for(int i=1;i<=n;i++) {
		cntp[0][i] = cntp[0][i - 1], cntp[1][i] = cntp[1][i - 1];
		if( s[i] == '?' ) m++;
		else cntp[s[i] - '0'][i]++;
	}
	for(int i=n;i>=1;i--) {
		cnts[0][i] = cnts[0][i + 1], cnts[1][i] = cnts[1][i + 1];
		if( s[i] != '?' ) cnts[s[i] - '0'][i]++;
	}
	
	ll tmp = 0;
	for(int i=1;i<=n;i++) {
		if( s[i] == '0' ) tmp += 1ll * x * cnts[1][i] + 1ll * y * cntp[1][i];
		else if( s[i] == '1' ) tmp += 1ll * y * cnts[0][i] + 1ll * x * cntp[0][i];
	}
	tmp /= 2;
	
	ll ans = (1ll << 60), tmp2 = 0;
	for(int i=1;i<=n;i++) if( s[i] == '?' )
		tmp2 += 1ll * x * cnts[1][i] + 1ll * y * cntp[1][i];
	ans = std::min(ans, tmp2);
	for(int i=1,t=0;i<=n;i++) if( s[i] == '?' ) {
		t++;
		tmp2 -= 1ll * x * cnts[1][i] + 1ll * y * cntp[1][i];
		tmp2 += 1ll * y * cnts[0][i] + 1ll * x * cntp[0][i];
		ans = std::min(ans, tmp2 + 1ll * y * t * (m - t));
	}
	
	tmp2 = 0;
	for(int i=1;i<=n;i++) if( s[i] == '?' )
		tmp2 += 1ll * y * cnts[0][i] + 1ll * x * cntp[0][i];
	ans = std::min(ans, tmp2);
	for(int i=1,t=0;i<=n;i++) if( s[i] == '?' ) {
		t++;
		tmp2 -= 1ll * y * cnts[0][i] + 1ll * x * cntp[0][i];
		tmp2 += 1ll * x * cnts[1][i] + 1ll * y * cntp[1][i];
		ans = std::min(ans, tmp2 + 1ll * x * t * (m - t));
	}
	
	printf("%lld\n", ans + tmp);
}
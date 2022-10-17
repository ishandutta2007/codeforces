#include <cmath>
#include <cstdio>
#include <algorithm>

int n, ans = - (1 << 30) ;

inline int red() {
	int Res ; bool flg ; char ch ; Res = flg = 0 ;
	while (ch = getchar(), ch < 48 || 57 < ch) flg ^= ! (ch ^ '-') ; Res = ch & 15 ;
	while (ch = getchar(), 47 < ch && ch < 58) Res = (Res << 1) + (Res << 3) + (ch & 15) ;
	if (flg) return - Res ; return Res ;
}

int main() {
	n = red() ;
	for (int i = 1; i <= n ; ++ i) {
		int x = red() ;
		if (x < 0) {
			ans = std :: max(ans, x) ;
		} else {
			int k = sqrt(x) ;
			if (k * k != x) ans = std :: max(ans, x) ;
		}
	}
	printf("%d\n", ans) ;
	return 0 ;
}
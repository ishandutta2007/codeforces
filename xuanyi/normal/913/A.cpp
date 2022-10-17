#include <cstdio>

int n, m ;

inline int red() {
	int Res ; bool flg ; char ch ; Res = flg = 0 ;
	while (ch = getchar(), ch < 48 || 57 < ch) flg ^= ! (ch ^ '-') ; Res = ch & 15 ;
	while (ch = getchar(), 47 < ch && ch < 58) Res = (Res << 1) + (Res << 3) + (ch & 15) ;
	if (flg) return - Res ; return Res ;
}

int main() {
	n = red(), m = red() ;
	for (int i = 1 ; i <= n ; ++ i) {
		if (m < (1ll << i)) {
			printf("%d\n", m) ;
			return 0 ;
		}
	}
	printf("%d\n", m % (1 << n)) ;
	return 0 ;
}
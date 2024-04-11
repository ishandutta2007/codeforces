#include <cstdio>
#define MAXN 1005
#define MAXS 5005
using namespace std ;

int T, n, l[MAXN], r[MAXN], ans[MAXN], Q[MAXS];

inline int red() {
	int Res ; bool flg ; char ch ; Res = flg = 0 ;
	while (ch = getchar(), ch < 48 || 57 < ch) flg ^= ! (ch ^ '-') ; Res = ch & 15 ;
	while (ch = getchar(), 47 < ch && ch < 58) Res = (Res << 1) + (Res << 3) + (ch & 15) ;
	if (flg) return - Res ; return Res ;
}

int main() {
	T = red() ;
	while (T --) {
		n = red() ; int j = 1 ;
		for (int i = 1 ; i <= n ; ++ i) l[i] = red(), r[i] = red() ;
		for (int i = 1 ; i <= 5000 ; ) {
			if (l[j] <= i && i <= r[j]) ans[j ++] = i ++ ; else
			if (j <= n && r[j] < i) ans[j ++] = 0 ; else
				++ i ;
		}
		for (int i = 1 ; i < n ; ++ i) printf("%d ", ans[i]) ; printf("%d\n", ans[n]) ;
		
	}
	return 0 ;
}
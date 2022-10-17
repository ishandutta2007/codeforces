#include <cstdio>
#include <algorithm>
#define MAXN 205
using namespace std ;

int T, N, K, ans, Num[MAXN];

inline int red() {
	int Res ; bool flg ; char ch ; Res = flg = 0 ;
	while (ch = getchar(), ch < 48 || 57 < ch) flg ^= ! (ch ^ '-') ; Res = ch & 15 ;
	while (ch = getchar(), 47 < ch && ch < 58) Res = (Res << 1) + (Res << 3) + (ch & 15) ;
	if (flg) return - Res ; return Res ;
}

int main() {
	T = red() ;
	while (T --) {
		N = red(), K = red() ;
		for (int i = 1 ; i <= K ; ++ i) Num[i] = red() ;
		int ans = max(Num[1], N - Num[K] + 1) ;
		for (int i = 1 ; i < K ; ++ i) 
			ans = max(ans, Num[i + 1] - Num[i] + 2 >> 1) ;
		printf("%d\n", ans) ;
	}
	return 0 ;
}
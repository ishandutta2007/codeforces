#include <cstdio>
#include <algorithm>
#define MAXN 100005

int n, A[MAXN] ;

inline int red() {
	int Res ; bool flg ; char ch ; Res = flg = 0 ;
	while (ch = getchar(), ch < 48 || 57 < ch) flg ^= ! (ch ^ '-') ; Res = ch & 15 ;
	while (ch = getchar(), 47 < ch && ch < 58) Res = (Res << 1) + (Res << 3) + (ch & 15) ;
	if (flg) return - Res ; return Res ;
}

int main() {
	n = red() ;
	for (int i = 1; i <= n ; ++ i) ++ A[red()] ;
	for (int i = 100000 ; i ; -- i) 
		if (A[i] & 1) {puts("Conan") ; return 0 ;}
	puts("Agasa") ;
	return 0 ;
}
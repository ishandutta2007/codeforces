#include <cstdio>
const int MAXW = 100005, INF = 0x3f3f3f3f ;

int w, l, Head, Tail;
int a[MAXW], b[MAXW], Q[MAXW], f[MAXW] ;

template <typename T>
inline T max(const T x, const T y) {
	if (x < y) return y ;
	return x ;
}

template <typename T>
inline T min(const T x, const T y) {
	if (x < y) return x ;
	return y ;
}

int main() {
	scanf("%d%d", &w, &l) ;
	for (int i = 1 ; i < w ; i++) scanf("%d", a+i) ; a[w] = INF ;
	b[0] = INF, Q[++Tail] = 0 ; 
	for (int i = 1 ; i <= w ; i++) if (a[i]){
		while (Head != Tail && Q[Head + 1] < i - l) Head++ ;
		while (Head != Tail) {
			Head++ ;
			if (b[ Q[Head] ] <= a[i]-b[i]) {
				b[i] += b[ Q[Head] ] ; 
			}
			else {
				b[ Q[Head--] ] -= a[i] - b[i] ;
				b[i] = a[i] ;
				break ;
			}
		}
		if (b[i]) Q[++Tail] = i ;
	}
	printf("%d\n", b[w]) ;
	return 0 ;
}
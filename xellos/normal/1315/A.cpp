#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int a,b,x,y;
		scanf("%d %d %d %d", &a, &b, &x, &y);
		int ans = 0;
		if(x*b >= ans) ans = x*b;
		if((a-1-x)*b >= ans) ans = (a-1-x)*b;
		if(y*a >= ans) ans = y*a;
		if((b-1-y)*a >= ans) ans = (b-1-y)*a;
		printf("%d\n", ans);
	}
}
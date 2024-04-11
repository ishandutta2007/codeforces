#include <bits/stdc++.h>

const int N = 1000000;
const int P = int(1E9) + 7;
inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int)(1ll * x * y % P);}

char s[N + 5]; int n;
int a[N + 5], b[N + 5], tp;
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	
	int ans = 1, ri = n;
	for(int i=n;i>=0;i--) {
		if( s[i] == '1' ) {ri = i; ans = mul(ans, n - i + 1); break;}
		if( i == 0 ) {printf("%d\n", n); return 0;}
	}
	
	int sum = 0, res = 0, cnt = 0; tp = 0;
	for(int i=ri;i>=1;i--) {
		if( s[i] == '1' ) {
			int lst = P - 1;
			while( tp >= 1 && a[tp] <= cnt )
				res = sub(res, mul(b[tp], sub(a[tp], lst))), lst = a[tp--];
			if( tp ) {
				res = sub(res, mul(b[tp], sub(a[tp], lst)));
				res = add(res, mul(b[tp], sub(a[tp], cnt)));
			}
			
			b[++tp] = sum, a[tp] = cnt, res = add(res, mul(sum, cnt + 1));
			sum = add(res, 1);
			cnt = 0;
		} else cnt++;
	}
	printf("%d\n", mul(cnt + 1, mul(ans, sum)));
}
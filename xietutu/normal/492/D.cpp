#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
int n,sum,size,b[2000005];
long long x,y,tx,ty;
int main() {
	scanf("%d%I64d%I64d",&n,&x,&y);
	tx = ty = 1; size = 0;
	while (tx <= x && ty <= y) {
		if (tx * y == ty * x) {
			b[size++] = 3; b[size++] = 3;
			++tx; ++ty;
		}
		else if (tx * y < ty * x) {
			b[size++] = 1; ++tx;
		}
		else {
			b[size++] = 2; ++ty;
		}
	}
	sum = x + y;
	for (int i = 1; i <= n; ++i) {
		int v;
		scanf("%d%",&v);
		v = (v - 1) % sum;
		if (b[v] == 3) printf("Both\n");
		else if (b[v] == 1) printf("Vanya\n");
		else printf("Vova\n");
	}
}
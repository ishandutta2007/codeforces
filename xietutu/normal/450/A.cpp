#include <cstdio>
#include <algorithm>
int a[105],b[105],now,n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i) scanf("%d",a + i);
	for (int i = 1; i <= n; ++i) b[i] = i;
	int now = n; 
	while (now != 1) {
		int x = b[1];
		a[x] -= m;
		for (int i = 1; i < now; ++i) b[i] = b[i + 1];
		if (a[x] > 0) b[now] = x;
		else --now;
	}
	printf("%d",b[1]);
}
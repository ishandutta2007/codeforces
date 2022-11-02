#include<cstdio>
const int MAXN = 100;
int main() {
	int n, x;
	scanf("%d", &n);
	int xs = 0, ys = 0;
	for(int i=1;i<=n;i++) {
		scanf("%d", &x);
		xs += x;
	}
	for(int i=1;i<=n;i++) {
		scanf("%d", &x);
		ys += x;
	}
	if( xs >= ys ) printf("Yes\n");
	else printf("No\n");
}
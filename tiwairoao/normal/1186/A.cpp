#include<cstdio>
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if( m >= n && k >= n ) puts("Yes");
	else puts("No");
}
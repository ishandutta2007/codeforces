#include<cstdio>
#include<cstring>
const int MAXN = 1000000;
char a[MAXN + 5], b[MAXN + 5];
int main() {
	scanf("%s%s", a + 1, b + 1);
	int lena = strlen(a + 1), lenb = strlen(b + 1);
	int x = 0, y = 1, ans = 0;
	for(int i=1;i<lenb;i++)
		x ^= (b[i] != b[i+1]);
	for(int i=1;i<lenb;i++)
		y ^= (a[i] != b[i]);
	y ^= x;
	for(int i=1;i<=lena-lenb+1;i++) {
		y ^= x, y ^= (a[i-1] != b[1]), y ^= (a[i+lenb-1] != b[lenb]);
		if( y == 0 ) ans++;
	}
	printf("%d\n", ans);
}
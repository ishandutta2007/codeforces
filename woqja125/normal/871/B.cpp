#include<stdio.h>
int x[10001]; // p0 ^ bi
int y[10001]; // pi ^ b0
int p[10001];
int ans[10001];
int chk[10001];
int b[10001];
int n;
int p0i(int i) {
	return x[0] ^ y[i];
}
void make(int p0) {
	p[0] = p0;
	for (int i = 1; i < n; i++) p[i] = p0i(i) ^ p0;
	for (int i = 0; i < n; i++) b[p[i]] = i;
}
bool test() {
	for (int i = 0; i < n; i++) chk[i] = 0;
	for (int i = 0; i < n; i++) chk[p[i]]++;
	for (int i = 0; i < n; i++) if (chk[i] != 1) return false;
	for (int i = 0; i < n; i++) if (x[i] != (p[0] ^ b[i]) || y[i] != (p[i]^b[0])) return false;
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("? 0 %d\n", i); fflush(stdout);
		scanf("%d", x + i);
		printf("? %d 0\n", i); fflush(stdout);
		scanf("%d", y + i);
	}
	long long c = 0;
	for (int i = 0; i < n; i++) {
		make(i);
		if (test()) {
			c++;
			for (int j = 0; j < n; j++)ans[j] = p[j];
		}
	}
	printf("!\n%d\n", c);
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	return 0;
}
#include <cstdio>

int a[30002], b[30004];
int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	int coin = 0;
	int last = -1, last_n = 0;
	for(i = 1; i <= n; i++) {
		if(b[i] == 0 && last_n > 0) {
			coin += i - last;
			last_n--;
		} else if(b[i] > 1) {
			coin += (i - last) * last_n;
			last_n += b[i] - 1;
			last = i;
		}
	}
	while(last_n > 0) {
		coin += (i - last);
		last_n--; i++;
	}
	printf("%d\n", coin);
	return 0;
}
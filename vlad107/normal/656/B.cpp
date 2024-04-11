#include <stdio.h>
#include <iostream>

using namespace std;

int n, a[500], b[500];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	int C = 1e7;
	int cnt = 0;
	for (int it = 1; it <= C; it++) {
		for (int i = 0; i < n; i++) if (it % a[i] == b[i]) {
			cnt++;
			break;
		}
	}
	// cout << cnt * 1.0 / C << endl;
	printf("%.10lf\n", cnt * 1.0 / C);
}
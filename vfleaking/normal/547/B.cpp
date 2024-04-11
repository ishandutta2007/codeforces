#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 200000;

template <class T>
inline void relax(T &a, const T &b) {
	if (b > a) {
		a = b;
	}
}

int main() {
	int n;
	static int a[MaxN + 1];
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	static int fl[MaxN + 1], fr[MaxN + 1];
	fl[1] = 1;
	for (int i = 2; i <= n; i++) {
		fl[i] = i;
		while (fl[i] > 1 && a[fl[i] - 1] >= a[i]) {
			fl[i] = fl[fl[i] - 1];
		}
	}
	fr[n] = n;
	for (int i = n - 1; i >= 1; i--) {
		fr[i] = i;
		while (fr[i] < n && a[fr[i] + 1] >= a[i]) {
			fr[i] = fr[fr[i] + 1];
		}
	}
	
	static int f[MaxN + 1];
	for (int i = 1; i <= n; i++)
		relax(f[fr[i] - fl[i] + 1], a[i]);
	
	for (int i = n - 1; i >= 1; i--)
		relax(f[i], f[i + 1]);
	
	for (int i = 1; i <= n; i++) {
		printf("%d ", f[i]);
	}
	printf("\n");
	
	return 0;
}
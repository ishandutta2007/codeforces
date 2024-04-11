#include <iostream>
#include <cstdio>
#include <vector>

int main() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	int base = 1;
	for(int i = 0; i + k < n; i++) {
		a[i] = i + 1;
		base = i + 2;
	}
	int top = n;
	for(int i = n - k; i < n; i++) {
		if((i + n - k) % 2 == 0) {
			a[i] = top--;
		} else {
			a[i] = base++;
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
	}
}
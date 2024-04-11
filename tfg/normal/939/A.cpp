#include <iostream>

const int ms = 500500;

int a[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	bool ans = true;
	for(int i = 1; i <= n; i++) {
		int size = 1;
		int cur = a[i];
		while(size <= 3 && cur != i) {
			cur = a[cur];
			size++;
		}
		if(size == 3 && cur == i) {
			ans = false;
		}
	}
	if(!ans) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}
#include <iostream>

const int ms = 12 * 30;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int g[ms];
int a[ms];

int main() {
	for(int i = 0; i < ms; i++) {
		g[i] = months[i % 12];
	}
	g[1 + 12 * 5]++;
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	bool ans = false;
	for(int i = 0; i < 12 * 10; i++) {
		bool got = true;
		for(int j = 0; j < n; j++) {
			got = got && a[j] == g[i + j];
		}
		ans = ans || got;
	}
	if(ans) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}
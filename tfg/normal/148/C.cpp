#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a;
	int g, d;
	std::cin >> g >> d;
	if(g > 0 && d == 0 && g + 1 == n) {
		std::cout << "-1\n";
		return 0;
	}
	a.push_back(2);
	if(d == 0) {
		a.push_back(2);
	}
	int sum = 2;
	while(d--) {
		a.push_back(sum + 1);
		sum += sum + 1;
	}
	while(g--) {
		a.push_back(a.back() + 1);
	}
	while(a.size() < n) {
		a.push_back(1);
	}
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}
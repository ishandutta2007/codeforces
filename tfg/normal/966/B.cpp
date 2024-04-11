#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdio>

typedef std::pair<int, int> ii;

const int ms = 300300;

ii a[ms];

int main() {
	int n, size[2];
	std::cin >> n >> size[0] >> size[1];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	std::sort(a, a + n);
	int first = 1;
	while(first <= n && (size[0] + first - 1) / first > a[n - first].first) first++;
	int second = 1;
	while(second + first <= n && (size[1] + second - 1) / second > a[n - first - second].first) second++;
	if(first + second <= n) {
		std::cout << "Yes\n";
		std::cout << first << ' ' << second << '\n';
		for(int i = 1; i <= first; i++) {
			printf("%d%c", a[n - i].second, i == first ? '\n' : ' ');
		}
		for(int i = 1; i <= second; i++) {
			printf("%d%c", a[n - i - first].second, i == second ? '\n' : ' ');
		}
		return 0;
	}
	first = 1;
	while(first <= n && (size[1] + first - 1) / first > a[n - first].first) first++;
	second = 1;
	while(second + first <= n && (size[0] + second - 1) / second > a[n - first - second].first) second++;
	if(first + second <= n) {
		std::cout << "Yes\n";
		std::cout << second << ' ' << first << '\n';
		for(int i = 1; i <= second; i++) {
			printf("%d%c", a[n - i - first].second, i == second ? '\n' : ' ');
		}
		for(int i = 1; i <= first; i++) {
			printf("%d%c", a[n - i].second, i == first ? '\n' : ' ');
		}
	} else {
		std::cout << "No\n";
	}
}
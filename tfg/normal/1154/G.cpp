#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;
const int ms = 1e7 + 10;

int cnt[ms];
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		cnt[a[i]]++;
	}
	long long ans[3] = {INF, INF, INF};
	for(int i = 1; i < ms; i++) {
		int got = 0;
		int arr[2] = {-1, -1};
		for(int j = i; j < ms; j += i) {
			for(int k = 0; got < 2 && k < cnt[j]; k++) {
				arr[got++] = j;
			}
		}
		if(got == 2 && (long long) arr[0] * arr[1] / i < ans[0]) {
			ans[0] = (long long) arr[0] * arr[1] / i;
			ans[1] = arr[0];
			ans[2] = arr[1];
		}
	}
	int i = 0, j = 0;
	while(a[i] != ans[1]) i++;
	while(i == j || a[j] != ans[2]) j++;
	if(i > j) std::swap(i, j);
	std::cout << i + 1 << ' ' << j + 1 << '\n';
}
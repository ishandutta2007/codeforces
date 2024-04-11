#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>
#include <type_traits>
#include <exception>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long sum = 0;
	std::cin >> n;
	while (n--) {
		long long x;
		std::cin >> x;
		sum += x;
	}
	std::cout << sum << std::endl;
	return 0;
}
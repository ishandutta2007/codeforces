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

std::vector<int> lims {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	std::cin >> x;
	int i = lims.size() - 1;
	while ((i > 0) && (lims[i - 1] > x)) --i;
	std::cout << lims[i] << std::endl;
	return 0;
}
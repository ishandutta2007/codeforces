#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

typedef long long ll; // dist_t
const ll INF = std::numeric_limits<ll>::max();

ll sqr(int x) {return ll(x) * x;}

std::vector<int> a;

ll f(int l, int h) { // calculate squared min.dist of points (i, a[i]) where l <= i < h
	ll result = INF;
	if (h - l <= 10) {
		for (int i = l; i < h-1; ++i)
			for (int j = i+1; j < h; ++j)
				result = std::min(result, sqr(i-j) + sqr(a[i]-a[j]));
		// std::cout << "(" << l << ", " << h << ") ===> " << result << "\n";
		//if (h - l <= 3)
		return result;
	}
	int mid = (l+h)/2;		// not overflow
	result = std::min(f(l, mid), f(mid, h));
	std::vector<int> pos;
	int d = /*std::floor*/ (int) std::sqrt(result);
	for (int i = std::max(mid - d, l); i < std::min(mid + d, h); ++i)
		// i <= floor(mid-1/2 + result)
		pos.push_back(i);
	std::sort(pos.begin(), pos.end(), [](int x, int y)->bool {
		return a[x] < a[y];
	});
	const int gap = 8;
	for (int i = 0; i < int(pos.size())-1; ++i) {
		for (int j = 1; j <= std::min(int(pos.size())-i-1, gap); ++j) {
			result = std::min(result, sqr(pos[i]-pos[i+j]) + sqr(a[pos[i]]-a[pos[i+j]]));
		}
	}
	// std::cout << "(" << l << ", " << h << ") => " << result << "\n";
	return result;
}

int main() {
	int n;
	std::cin >> n; a.resize(n);
	for (int& i : a) std::cin >> i;
	for (int i = 1; i < n; ++i) a[i] += a[i-1];
	// for (int i = 0; i < n; ++i) std::cout << i << ":" << a[i] << "\n";
	// std::cout << " <-- DEBUG DATA \n";
	std::cout << f(0, n) << "\n";
}


/*
8
11 12 13 14 15 -29 -13 -23


*/
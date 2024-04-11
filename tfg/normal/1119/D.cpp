#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	a.resize(std::unique(a.begin(), a.end()) - a.begin());
	std::vector<long long> event;
	n = (int) a.size();
	for(int i = 0; i + 1 < n; i++) {
		event.push_back(a[i+1] - a[i] - 1);
	}
	std::sort(event.begin(), event.end());
	int m;
	std::cin >> m;
	std::vector<long long> qry;
	std::vector<int> p(m);
	for(int i = 0; i < m; i++) {
		long long l, r;
		p[i] = i;
		std::cin >> l >> r;
		qry.push_back(r - l);
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return qry[v1] < qry[v2]; });
	long long aa = n;
	long long b = n;
	int pt = 0;
	for(auto id : p) {
		long long x = qry[id];
		while(pt < (int) event.size() && event[pt] <= x) {
			//std::cout << "event at " << event[pt] << '\n';
			aa--;
			b += event[pt++];
		}
		qry[id] = aa * x + b;
	}
	for(int i = 0; i < m; i++) {
		std::cout << qry[i] << (i + 1 == m ? '\n' : ' ');
	}

}
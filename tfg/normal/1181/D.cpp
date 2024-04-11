#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;

int tree[ms];

void upd(int x) {
	for(; x < ms; x += x & -x) {
		tree[x]++;
	}
}

int qryy(int x) {
	int ans = 0;
	for(; x > 0; x -= x & -x) {
		ans += tree[x];
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector< std::pair<int, int> > city;
	for(int i = 1; i <= m; i++) {
		city.emplace_back(0, i);
	}
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		city[x-1].first++;
	}
	std::sort(city.begin(), city.end());
	std::vector< std::pair<long long, int> > qries;
	for(int i = 0; i < q; i++) {
		long long x;
		std::cin >> x;
		qries.emplace_back(x, i);
	}
	std::sort(qries.begin(), qries.end());
	int pt = 0;
	long long l = n+1, r = n+1;
	const long long INF = 2e18;
	std::vector<int> ans(q, -1);
	for(auto qry : qries) {
		while(qry.first >= r) {
			l = r;
			int val = city[pt].first;
			while(pt < m && city[pt].first == val) {
				//std::cout << "including " << city[pt].second << std::endl;
				upd(city[pt++].second);
			}
			r = pt == m ? INF : l + (long long) pt * (city[pt].first - val);
			//std::cout << "pt at " << pt << ", got [" << l << ", " << r << ")" << std::endl;
		}
		int lp = 1, rp = m;
		int pos = (qry.first - l) % pt + 1;
		//std::cout << "pos is " << pos << '\n';
		while(lp != rp) {
			int mid = (lp + rp) / 2;
			//std::cout << "asking for " << mid << ", got " << qryy(mid) << std::endl;
			if(qryy(mid) >= pos) {
				rp = mid;
			} else {
				lp = mid + 1;
			}
		}
		ans[qry.second] = lp;
	}
	for(auto v : ans) {
		std::cout << v << '\n';
	}
}
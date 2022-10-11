#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

typedef std::pair<int, int> ii;

std::vector<ii> fix(std::vector<ii> a) {
	std::sort(a.begin(), a.end());
	std::vector<ii> ans;
	int begin = a[0].first;
	int end = a[0].second;
	for(int i = 1; i < a.size(); i++) {
		if(end + 1 >= a[i].first) {
			end = std::max(a[i].second, end);
		} else {
			ans.emplace_back(begin, end);
			begin = a[i].first;
			end = a[i].second;
		}
	}
	ans.emplace_back(begin, end);
	return ans;
}

long long get_len(std::vector<ii> a) {
	long long ans = 0;
	for(auto inter : a) {
		//std::cout << inter.first << ", " << inter.second << "\n";
		ans += inter.second - inter.first + 1;
	}
	return ans;
}

struct Info {
	int pos, tim, val;

	Info(int i, int j, int k) {
		pos = i;
		tim = j;
		val = k;
	}
};

bool operator < (Info a, Info b) {
	return a.tim < b.tim;
}

struct BIT {
	std::vector<int> bit;
	int n;

	BIT(int n = 0) {
		bit.assign(n + 1, 0);
		this->n = n;
	}

	void upd(int x, int v) {
		//std::cout << "making upd on " << x << "\n";
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}

	int qry(int x) {
		//std::cout << "making query on " << x << "\n";
		int ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}
};

int main() {
	std::map<int, std::vector<ii> > lines[2];
	int n;
	std::cin >> n;
	std::vector<int> pts;
	for(int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) {
			std::swap(x1, x2);
		}
		if(y1 > y2) {
			std::swap(y1, y2);
		}
		if(x1 == x2) {
			lines[0][x1].push_back(ii(y1, y2));
		} else {
			lines[1][y1].push_back(ii(x1, x2));
		}
		pts.push_back(x1);
		pts.push_back(x2 + 1);
		pts.push_back(x2);
		pts.push_back(y1);
		pts.push_back(y2);
		pts.push_back(y2 + 1);
	}
	long long ans = 0;
	std::vector<Info> events;
	for(auto &a : lines[0]) {
		//std::cout << "for x == " << a.first << " got\n";
		a.second = fix(a.second);
		ans += get_len(a.second);
		for(auto b : a.second) {
			events.emplace_back(a.first, b.first, 1);
			events.emplace_back(a.first, b.second + 1, -1);
		}
	}
	std::sort(events.begin(), events.end());
	std::sort(pts.begin(), pts.end());
	BIT fw(pts.size() + 10);
	int inc = 0;
	for(auto &a : lines[1]) {
		//std::cout << "for y == " << a.first << " got\n";
		a.second = fix(a.second);
		ans += get_len(a.second);
		while(inc != events.size() && events[inc].tim <= a.first) {
			//std::cout << "processing event " << events[inc].pos << ", " << events[inc].val << "\n";
			fw.upd(std::lower_bound(pts.begin(), pts.end(), events[inc].pos) - pts.begin() + 1, events[inc].val);
			inc++;
		}
		for(auto b : a.second) {
			//std::cout << "segment is (" << b.first << ", " << b.second << ")\n";
			ans += fw.qry(std::lower_bound(pts.begin(), pts.end(), b.first) - pts.begin())
				 - fw.qry(std::upper_bound(pts.begin(), pts.end(), b.second) - pts.begin());
		}
	}
	std::cout << ans << '\n';
}
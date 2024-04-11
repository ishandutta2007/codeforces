#include <iostream>
#include <string>
#include <set>
#include <cstdio>

const int ms = 200200;

std::set<int> pos[256];

int fw[ms];

void upd(int x) {
	for(; x < ms; x += x & -x) {
		fw[x]++;
	}
}

int qry(int x) {
	int ans = 0;
	for(; x > 0; x -= x & -x) {
		ans += fw[x];
	}
	return ans;
}

int get_pos(int x) {
	int l = 1, r = ms;
	while(l != r) {
		int mid = (l + r) / 2;
		int pos = mid - qry(mid);
		if(pos < x) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}

int main() {
	int n, m;
	std::string str;
	std::cin >> n >> m >> str;
	for(int i = 0; i < n; i++) {
		pos[str[i]].insert(i + 1);
	}
	while(m--) {
		int l, r;
		//std::cin >> l >> r;
		char c;
		//std::cin >> c;
		scanf("%i %i %c", &l, &r, &c);
		//std::cout << "qry (" << l << ", " << r << ", " << c << ")\n";
		l = get_pos(l);
		r = get_pos(r);
		//std::cout << "got (" << l << ", " << r << ")\n";
		while(1) {
			auto it = pos[c].lower_bound(l);
			if(it == pos[c].end() || *it > r) {
				break;
			}
			//std::cout << "deleting " << *it << '\n';
			upd(*it);
			pos[c].erase(it);
		}
	}
	for(int i = 0; i < n; i++) {
		if(qry(i + 1) - qry(i) == 0) {
			std::cout << str[i];
		}
	}
	std::cout << '\n';
}
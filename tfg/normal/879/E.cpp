#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int k;
struct Group {
	void read() {
		for(int i = 0; i < k; i++) {
			std::cin >> mn[i];
			mx[i] = mn[i];
		}
		size = 1;
	}

	int size;
	int mx[10], mn[10];

	void merge(const Group &o) {
		for(int i = 0; i < k; i++) {
			mx[i] = std::max(mx[i], o.mx[i]);
			mn[i] = std::min(mn[i], o.mn[i]);
		}
		size += o.size;
	}

	int score(const Group &o) const {
		int ans = 0;
		for(int i = 0; i < k; i++) {
			if(o.mx[i] > mn[i]) {
				ans |= 1;
			}
			if(mx[i] > o.mn[i]) {
				ans |= 2;
			}
		}
		// 3 is can draw
		// 1 is always loses
		// 2 is always wins
		return ans;
	}

	void print() const {
		for(int i = 0; i < k; i++) {
			std::cout << mn[i] << ' ' << mx[i] << '\n';
		}
		std::cout << "of size " << size << '\n';
	}

	bool operator < (const Group &o) const {
		return score(o) == 1;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> k;
	std::set<Group> st;
	while(n--) {
		Group cur;
		cur.read();
		auto it = st.lower_bound(cur);
		auto it2 = it;
		while(it2 != st.end() && it2->score(cur) == 3) {
			cur.merge(*it2);
			it2++;
		}
		st.erase(it, it2);
		//std::cout << "inserting group:\n";
		//cur.print();
		st.insert(cur);
		std::cout << st.rbegin()->size << std::endl;
	}
}
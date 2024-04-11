#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 3030;

struct Vertex {
	int id;
	std::vector<int> e;
	std::bitset<ms> bits;
	void addEdge(int x) {
		e.push_back(x);
		bits[x] = true;
	}

	std::vector<int> inter(const Vertex &o) const {
		//if(e.size() > o.e.size()) return o.inter(*this);
		std::vector<int> ans;
		for(auto x : e) {
			if(x != o.id && o.bits[x]) ans.push_back(x);
		}
		return ans;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<Vertex> a(n), b(n);
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		a[u].addEdge(v);
		b[v].addEdge(u);
	}
	for(int i = 0; i < n; i++) {
		a[i].id = b[i].id = i;
		std::sort(a[i].e.begin(), a[i].e.end());
		std::sort(b[i].e.begin(), b[i].e.end());
	}
	long long ans = 0;
	std::vector<int> A, B, C;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			A = a[i].inter(a[j]);
			B = b[i].inter(b[j]);
			ans += (long long) A.size() * B.size();
			for(int l = 0, r = 0; l < (int) A.size() && r < (int) B.size(); ) {
				if(A[l] == B[r]) {
					l++;
					r++;
					ans--;
				} else if(A[l] < B[r]) {
					l++;
				} else {
					r++;
				}
			}
		}
	}
	std::cout << ans << '\n';
}
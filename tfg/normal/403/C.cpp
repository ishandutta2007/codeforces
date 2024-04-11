#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const int N>
struct BinaryMatrix {
	std::bitset<N> mat[N];

	BinaryMatrix operator *(const BinaryMatrix &o) const {
		BinaryMatrix ans;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(mat[i][j]) {
					ans.mat[i] |= o.mat[j];
				}
			}
		}
		return ans;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> edges(n);
	std::vector<std::vector<int>> rev(n);
	int root = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int v;
			std::cin >> v;
			if(v > 0) {
				if(i == j) root = i;
				else {
					edges[i].push_back(j);
					rev[j].push_back(i);
				}
			}
		}
	}
	//std::cout << "root is " << root << std::endl;
	bool valid = true;
	std::bitset<2000> visit;
	std::queue<int> q;
	visit.reset();
	q.push(root);
	visit[root] = true;
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		//std::cout << "visiting " << on << std::endl;
		for(auto to : edges[on]) {
			if(!visit[to]) {
				visit[to] = true;
				q.push(to);
			}
		}
	}
	valid = valid && (int) visit.count() == n;
	visit.reset();
	q.push(root);
	visit[root] = true;
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		//std::cout << "visiting " << on << std::endl;
		for(auto to : rev[on]) {
			if(!visit[to]) {
				visit[to] = true;
				q.push(to);
			}
		}
	}
	valid = valid && (int) visit.count() == n;
	std::cout << (valid ? "YES\n" : "NO\n");
}
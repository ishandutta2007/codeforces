#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 7;

struct Number {
	Number(int x = 1) {
		for(int i = 0; i < me; i++) {
			p[i] = 0;
		}
		int id = 0;
		for(int i = 2; i * i <= x; i++) {
			if(x % i == 0) {
				while(x % i == 0) {
					x /= i;
					p[id]++;
				}
				id++;
			}
		}
		if(x > 1) {
			p[id++] = 1;
		}
		std::sort(p, p + id);
		std::reverse(p, p + id);
	}
	int p[me];
	int divs() {
		int ans = 1;
		for(int i = 0; i < me; i++) {
			ans *= p[i] + 1;
		}
		return ans;
	}

	bool operator < (const Number &o) const {
		for(int i = 0; i < me; i++) {
			if(p[i] != o.p[i]) {
				return p[i] < o.p[i];
			}
		}
		return false;
	}

	bool operator == (const Number &o) const {
		for(int i = 0; i < me; i++) {
			if(p[i] != o.p[i]) {
				return false;
			}
		}
		return true;
	}

	void print() {
		for(int i = 0; i < me; i++) {
			std::cout << p[i] << (i + 1 == me ? '\n' : ' ');
		}
	}
};

Number lul;
std::vector<Number> numbers;
std::vector<int> vals;

void bf(int on = 0, int sum = 0, int lim = 22) {
	if(on == me) {
		numbers.push_back(lul);
		vals.push_back(lul.divs());
		return;
	}
	for(int i = 0; i <= lim && i + sum <= 22; i++) {
		lul.p[on] = i;
		bf(on + 1, sum + i, i);
	}
}

std::vector<int> edges[3030];
int dist[3030];
int table[3030][600];
bool visit[3030];

int calc(int x) {
	int st = std::lower_bound(numbers.begin(), numbers.end(), Number(x)) - numbers.begin();
	if(visit[st]) {
		return st;
	}
	visit[st] = true;
	memset(dist, 0x3f, sizeof dist);
	memset(table[st], 0x3f, sizeof table[st]);
	dist[st] = 0;
	std::vector<int> q(1, st);
	for(int i = 0; i < (int) q.size(); i++) {
		int on = q[i];
		{
			int id = std::lower_bound(vals.begin(), vals.end(), numbers[on].divs()) - vals.begin();
			table[st][id] = std::min(table[st][id], dist[on]);
		}
		for(auto to : edges[on]) {
			if(dist[to] > 1 + dist[on]) {
				dist[to] = 1 + dist[on];
				q.push_back(to);
			}
		}
	}
	return st;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	bf();
	std::sort(vals.begin(), vals.end());
	vals.resize(std::unique(vals.begin(), vals.end()) - vals.begin());
	std::sort(numbers.begin(), numbers.end());
	for(int i = 0; i < (int) numbers.size(); i++) {
		for(int j = 0; j < me; j++) {
			auto to = numbers[i];
			to.p[j]++;
			int id = std::lower_bound(numbers.begin(), numbers.end(), to) - numbers.begin();
			if(id < (int) numbers.size() && numbers[id] == to) {
				edges[i].push_back(id);
			}
		}
		for(int j = 0; j < me; j++) {
			auto to = numbers[i];
			to.p[j]--;
			int id = std::lower_bound(numbers.begin(), numbers.end(), to) - numbers.begin();
			if(id < (int) numbers.size() && numbers[id] == to) {
				edges[i].push_back(id);
			}
		}
	}
	//std::cout << numbers.size() << ' ' << vals.size() << '\n';
	int t;
	std::cin >> t;
	while(t--) {
		int x, y;
		std::cin >> x >> y;
		//Number(x).print();
		//Number(y).print();
		x = calc(x);
		y = calc(y);
		int ans = 2193;
		for(int i = 0; i < (int) vals.size(); i++) {
			ans = std::min(ans, table[x][i] + table[y][i]);
		}
		std::cout << ans << '\n';
	}
}
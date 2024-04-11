#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <set>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

std::vector<int> primes[ms];
bool np[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		if(np[i]) continue;
		//std::cout << i << " is prime\n";
		for(int j = i; j < ms; j += i) {
			np[j] = true;
			int x = j;
			int e = 0;
			while(x % i == 0) {
				x /= i;
				e ^= 1;
			}
			if(e) {
				primes[j].push_back(i);
			}
		}
	}
	int n;
	std::cin >> n;
	std::map<int, int> IDS;
	std::vector<std::vector<int>> edges;
	std::vector<int> loops, ori;
	auto getID = [&](int x) {
		if(IDS.count(x)) {
			return IDS[x];
		} else {
			ori.push_back(x);
			int s = (int) IDS.size();
			loops.push_back(0);
			edges.emplace_back(0);
			//assert(s == (int) loops.size() - 1);
			return IDS[x] = s;
		}
	};
	std::set<int> haha;
	bool kek = false;
	while(n--) {
		int x;
		std::cin >> x;
		int s = 1;
		for(auto k : primes[x]) s *= k;
		//assert(primes[x] == primes[s] && (int) primes[x].size() <= 2);
		x = s;
		//std::cout << "(" << x << ", " << s << ")" << std::endl;
		if((int) primes[x].size() == 0) {
			//assert(x == 1);
			std::cout << "1\n";
			return 0;
		} else {
			if(haha.count(x)) {
				kek = true;
			}
			haha.insert(x);
			if((int) primes[x].size() == 1) {
				loops[getID(primes[x][0])]++;
				//assert(loops[getID(primes[x][0])] == 1);
			} else {
				getID(primes[x][0]);getID(primes[x][1]);
				edges[getID(primes[x][0])].push_back(getID(primes[x][1]));
				edges[getID(primes[x][1])].push_back(getID(primes[x][0]));
			}
		}
	}
	if(kek) {
		std::cout << "2\n";
		return 0;
	}
	n = (int) edges.size();
	int ans = n + 1;
	std::queue<int> q;
	for(int i = 0; i < n; i++) {
		if(ori[i] > 1000) continue;
		std::vector<int> dist(n, 1e9);
		std::vector<int> frm(n, -1);
		dist[i] = 0;
		q.push(i);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto to : edges[on]) {
				if(dist[to] > 1 + dist[on]) {
					dist[to] = 1 + dist[on];
					frm[to] = on;
					q.push(to);
				} else if(to != frm[on]) {
					ans = std::min(ans, 1 + dist[on] + dist[to]);
				} else {
					frm[on] = -1;
				}
			}
		}
		std::vector<int> mx(2, 1e9);
		for(int j = 0; j < n; j++) {
			if(!loops[j]) continue;
			if(mx[0] > dist[j]) {
				mx[1] = mx[0];
				mx[0] = dist[j];
			} else if(mx[1] > dist[j]) {
				mx[1] = dist[j];
			}
		}
		ans = std::min(ans, mx[0] + mx[1] + 2);
	}
	if(ans == n + 1) ans = -1;
	std::cout << ans << '\n';
}
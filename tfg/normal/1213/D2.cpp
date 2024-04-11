#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;
const int ms = 200200;

int k;

struct Heap {
	std::priority_queue<int> hp;
	int sum;
	
	Heap() { sum = 0; }
	
	void push(int x) {
		sum += x;
		hp.push(x);
		while(hp.size() > k) {
			sum -= hp.top();
			hp.pop();
		}
	}
	
	int get() {
		if(hp.size() != k) { return INF; }
		else { return sum; }
	}
};


Heap a[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> k;
	while(n--) {
		int x;
		std::cin >> x;
		a[x].push(0);
	}
	int ans = INF;
	for(int i = ms-1; i > 0; i--) {
		ans = std::min(ans, a[i].get());
		while(!a[i].hp.empty()) {
			a[i / 2].push(a[i].hp.top() + 1);
			a[i].hp.pop();
		}
	}
	std::cout << ans << '\n';
}
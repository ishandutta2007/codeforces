#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

template <class T = int>
struct MaxQueue {
	// DO NOT ACCESS AN EMPTY QUEUE
	struct Info {
		int freq;
		T val;
		Info() {}
		Info(int f, T v) {
			freq = f; val = v;
		}
	};

	std::vector<Info> queue;
	int pos;

	MaxQueue() { pos = 0; }

	void push(T v) {
		int freq = 1;
		while(queue.size() > pos && queue.back().val <= v) {
			freq += queue.back().freq;
			queue.pop_back();
		}
		queue.emplace_back(freq, v);
	}

	T getMax() {
		return queue[pos].val;
	}

	void pop() {
		queue[pos].freq--;
		if(queue[pos].freq == 0) {
			pos++;
		}
	}

	void clear() { queue.clear(); pos = 0; }
};

std::vector<int> a;

int main() {
	//std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a.begin(), a.end());
	std::vector<long long> left(n + 1, 0);
	std::vector<long long> right(n + 1, 0);
	for(int i = 0; i < n; i++) {
		left[i + 1] = a[i / m * m] + left[i / m * m];
	}
	for(int i = 0; i < n; i++) {
		right[n-1-i] = a[n-1 - i / m * m] + right[n - (i / m * m)];
	}
	/*for(int i = 0; i < n; i++) {
		std::cout << left[i] << (i + 1 == n ? '\n' : ' ');
	}
	for(int i = 0; i < n; i++) {
		std::cout << right[i] << (i + 1 == n ? '\n' : ' ');
	}*/
	long long ans = 1e18;
	for(int i = 0; i < n;) {
		int j = i;
		while(j < n && a[i] == a[j]) {
			j++;
		}
		ans = std::min(ans, -left[i] + right[j] + (long long)a[i] * ((i + m - 1) / m - (n - j + m - 1) / m));
		i = j;
	}
	std::cout << ans * 2 << std::endl;
}
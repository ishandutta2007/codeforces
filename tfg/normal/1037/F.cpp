#include <iostream>
#include <cstdio>
#include <vector>

template <class T, class C = std::less<T>>
struct MaxQueue {
	MaxQueue() {
		clear();
	}

	void clear() {
		sum = 0;
		id = 0;
		q.clear();
	}

	void push(T x) {
		std::pair<int, T> nxt(1, x);
		while(q.size() > id && cmp(q.back().second, x)) {
			nxt.first += q.back().first;
			sum -= (long long) q.back().first * q.back().second;
			q.pop_back();
		}
		q.push_back(nxt);
		sum += (long long) q.back().first * q.back().second;
	}

	T qry() {
		return q[id].second;
	}

	long long getSum() {
		return sum;
	}

	void pop() {
		q[id].first--;
		if(q[id].first == 0) {
			id++;
		}
	}
private:
	std::vector<std::pair<int, T>> q;
	long long sum;
	int id;
	C cmp;
};

const int ms = 2001000;
const int MOD = 1e9 + 7;

int a[ms];

int main() {
	// std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	MaxQueue<int> q;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		q.push(a[i]);
		//std::cout << "added " << a[i] << std::endl;
		if(i >= k - 1) {
			a[i - (k - 1)] = q.qry();
			//std::cout << "got " << q.qry() << std::endl;
			q.pop();
		}
	}
	k--;
	int ans = 0;
	std::vector<MaxQueue<int>> v(k);
	for(int i = n - 1; i >= 0; i--) {
		v[i % k].push(a[i]);
		//std::cout << a[i] << ": on " << i << " adding " << v[i % k].getSum() << std::endl;
		ans = (int) (ans + v[i % k].getSum() % MOD) % MOD;
		ans = (int) (ans - v[i % k].qry() % MOD) % MOD;
		ans = (ans + MOD) % MOD;
	}
	std::cout << ans << std::endl;
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2e6 + 10;

int n, ans;
int nxt[ms];
int a[ms];
int l[ms], r[ms];
std::vector<int> st;
void dfs(int on) {
	st.push_back(on);
	if(on < n) {
		ans = std::min(ans, (int) st.size());
		while(st[(int) st.size() - ans] >= on + n) {
			ans--;
		}
	}
	for(int to = l[on]; to <= r[on]; to++) {
		dfs(to);
	}
	st.pop_back();
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> n >> q;
	long long tot = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[n+i] = a[i];
		tot += a[i];
	}
	while(q--) {
		long long gap;
		std::cin >> gap;
		long long sum = 0;
		for(int i = 0; i < 2 * n; i++) {
			l[i] = 1e9;
			r[i] = -1;
		}
		for(int i = 0, j = 0; i < 2 * n; i++) {
			while(j - i < n && j+1 < 2 * n && sum + a[j] <= gap) sum += a[j++];
			nxt[i] = j;
			sum -= a[i];
			if(nxt[i] != i) {
				l[nxt[i]] = std::min(l[nxt[i]], i);
				r[nxt[i]] = std::max(r[nxt[i]], i);
			} else {
				assert(i + 1 == 2 * n);
			}
		}
		ans = n;
		dfs(2*n-1);
		std::cout << ans << '\n';
	}
}
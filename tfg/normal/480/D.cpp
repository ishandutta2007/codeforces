#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001;

struct DP {
	int in = -1, out = 3*ms, w = 0, s = ms-1, v = 0;
	int dp[ms];

	DP() {
		memset(dp, 0, sizeof dp);
	}

	void read() {
		std::cin >> in >> out >> w >> s >> v;
	}
};

template<class T>
class CoordinateCompression {
public:
	CoordinateCompression(const std::vector<T> &a) {
		arr = a;
		std::sort(arr.begin(), arr.end());
		arr.resize(std::unique(arr.begin(), arr.end()) - arr.begin());
	}

	int getL(T x) { return std::lower_bound(arr.begin(), arr.end(), x) - arr.begin(); }
	int getR(T x) { return std::upper_bound(arr.begin(), arr.end(), x) - arr.begin(); }
	int size() const { return (int) arr.size(); }
private:
	std::vector<T> arr;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, S;
	std::cin >> n >> S;
	std::vector<DP> a(n);
	for(int i = 0; i < n; i++) {
		a[i].read();
	}
	a.emplace_back();
	std::sort(a.begin(), a.end(), [](const DP &v1, const DP &v2) { return v1.out - v1.in < v2.out - v2.in; });
	std::vector<DP> st;
	for(auto cur : a) {
		std::vector<DP> under;
		std::vector<int> uni;
		for(int i = 0; i < (int) st.size(); i++) {
			if(cur.in <= st[i].in && st[i].out <= cur.out) {
				under.push_back(st[i]);
				uni.push_back(under.back().in);
				uni.push_back(under.back().out);
			}
		}
		if(!under.empty()) {
			CoordinateCompression<int> coord(uni);
			std::sort(under.begin(), under.end(), [](const DP &v1, const DP &v2) { return v1.out < v2.out; });
			std::vector<DP> row(coord.size());
			for(auto &lul : under) {
				lul.in = coord.getL(lul.in);
				lul.out = coord.getL(lul.out);
			}
			for(int i = 0, j = 0; i < (int) row.size(); i++) {
				if(i) {
					row[i] = row[i-1];
				}
				while(j < (int) under.size() && under[j].out == i) {
					for(int k = 0; k < ms; k++) {
						row[i].dp[k] = std::max(row[i].dp[k], row[under[j].in].dp[k] + under[j].dp[k]);
					}
					j++;
				}
			}
			for(int i = 0; i < ms; i++) {
				cur.dp[i] = row.back().dp[i];
			}
		}
		for(int i = ms-1; i >= cur.w; i--) {
			int j = std::min(i - cur.w, cur.s);
			cur.dp[i] = std::max(cur.dp[i], cur.dp[j] + cur.v);
		}
		for(int i = 1; i < ms; i++) {
			assert(cur.dp[i] >= cur.dp[i-1]);
		}
		/*std::cout << "[" << cur.in << ", " << cur.out << "), (" << cur.w << ", " << cur.s << ", " << cur.v << ")\n";
		for(int i = 0; i < ms; i++) {
			if(cur.dp[i] > 0) {
				std::cout << i << ": " << cur.dp[i] << "\n";
			}
		}*/
		st.push_back(cur);
	}
	//assert(st.size() == 1);
	std::cout << st.back().dp[S] << '\n';
}
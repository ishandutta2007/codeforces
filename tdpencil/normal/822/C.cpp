#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

#pragma GCC optimize("Ofast")
typedef long long ll;

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}
}

struct point {
	ll first, second;

	point(ll _first, ll _second) : first(_first) , second(_second) {}
	point() : first(0), second(0) {}

	bool operator <(const point other) {
		if(other.first == first)
			return second < other.second;
		return first < other.first;
	}
};
bool intersect(const point x, point y) {
	return !(x.second < y.first || y.second < x.first);
}

// sort by minimum cost
vector<pair<pair<int, int>, int>> duration[200001];
vector<int> suf[200001];

const int INF = 2e9 + 10;
void run_case() {
	int ans = INF;

	int N, X; cin >> N >> X;
	// we only have to search for the points and the
	vector<pair<pair<int, int>, int>> A(N);
	for(auto &i : A) {
		cin >> i.first.first >> i.first.second >> i.second;
		duration[(i.first.second - i.first.first + 1)].push_back(make_pair(make_pair(i.first.first, i.first.second), i.second));
	}

	for(int i = 0; i <= 200000; i++) {
		sort(duration[i].begin(), duration[i].end());
		if(duration[i].size() <= 0) continue;
		suf[i].resize(duration[i].size());
		suf[i][int(duration[i].size()) - 1] = duration[i][duration[i].size() - 1].second;
		for(int j = int(duration[i].size()) - 2; j >= 0; --j) {
			suf[i][j] = min(suf[i][j + 1], duration[i][j].second);
		}
	}
	// return;

	for(auto &i : A) {
		int other = X - (i.first.second - i.first.first + 1);
		if(other < 0) continue;
		int pos = upper_bound(duration[other].begin(), duration[other].end(), make_pair(make_pair(i.first.second, INF), 0)) - duration[other].begin();
		if(pos >= duration[other].size()) continue;
		int res = suf[other][pos];
		ans = min(ans, res + i.second);
	}
	// return;

	cout << (ans >= INF ? -1 : ans) << "\n";


}
int main() {
	
	
	io();
	int t = 1;
	// cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) run_case();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}
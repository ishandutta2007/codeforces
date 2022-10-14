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
#define ar array
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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
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
struct cmp {
	bool operator()(const ar<int, 3> &x, const ar<int, 3> &y) {
		return x[0] == y[0] ? (x[1] > y[1]) : x[0] < y[0];
	}
};
vector<int> adj[200000];
int N;

int deg[200000];

bool isLeaf(int vertex) {
	return deg[vertex] == 1;
}
void run_case() {
	cin >> N;
	for(int i = 1; i < N; i++) {
		int p; cin >> p;
		--p;
		adj[p].push_back(i);
		deg[i]++;
		deg[p]++;
	}
	bool works = true;
	for(int i = 0; i < N; i++) {
		if(isLeaf(i)) continue;
		int cnt =0 ;
		for(int v : adj[i]) {
			if(isLeaf(v)) cnt++;
		}
		works &= cnt >= 3;
	}

	cout << (works ? "Yes": "No");
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
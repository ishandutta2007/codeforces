#include <algorithm>
#include <unordered_set>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
const int64_t inf = 1e12;
using namespace std;
#define ll long long
#define sz(s) (int(s.size()))
#define all(x) x.begin(),x.end()
#define sum(x) accumulate(x.begin(), x.end(), 0LL)
#define vec vector
#define nl '\n'
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

inline void run_case() {
    int64_t N;
    cin >> N;
    int64_t x, y;
    cin >> x >> y;
    auto dist = [&](pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    pair<int64_t, int64_t> f = {N, N};
    pair<int64_t, int64_t> s = {1, 1};

    if(dist(s, {x, y}) <= dist(f, {x, y})) {
        cout << "White\n";
    } else {
        cout << "Black\n";
    }
}



int main() {
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while(t--)
		run_case();
}
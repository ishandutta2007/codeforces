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
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define ar array


void solve() {
	int N;
	cin >> N;

	vector<int> A(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];

	set<pair<int, int>> idx;

	for(int i =0; i < N; i++)
		idx.insert({A[i], i+1});

	int M; cin >> M;
	ll ans1=0,ans2=0;
	for(int i = 0; i < M; i++) {
		int p; cin >> p;
		ans1 += (*idx.lower_bound(make_pair(p, 0))).second;
		ans2 += N - (*idx.lower_bound(make_pair(p, 0))).second + 1;
	}

	cout << ans1 << " " << ans2 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}
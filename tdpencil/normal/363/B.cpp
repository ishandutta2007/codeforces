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

template<class T> struct rangeSum {
	vector<T> prefixSums;
	void init(vector<T> &a) {
		prefixSums = a;
		partial_sum(prefixSums.begin(), prefixSums.end(), prefixSums.begin());
	}
	T query(int l, int r) {
		assert(l >= 0 && r < int(prefixSums.size()));
		return l == 0 ? prefixSums[r] : prefixSums[r] - prefixSums[l-1];
	}
	void add(int l, int r, T val) {
		prefixSums[r] += val;
		prefixSums[l] -= val;
	}
};
void solve() {
	int N; cin >> N;
	int idx = 0;
	int mx = 1000000000;
	int K; cin >> K;
	vector<ll> A(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];
	rangeSum<ll> rq;
	rq.init(A);

	for(int i = 0; i < N-K+1; i++) {
		if(rq.query(i, i+K-1) < mx) {
			mx = rq.query(i, i+K-1);
			idx = i +1;
		}
	}

	cout << idx << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}
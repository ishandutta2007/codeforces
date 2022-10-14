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

ll A[200005];

int N;

void solve() {
	cin >> N;
	set<pair<ll, ll>> idx;

	for(int i = 0; i < N; i++)
		cin >> A[i], idx.insert({A[i], i+1});

	sort(A, A+N);
	vector<ll> prefixSums(N+1);

	for(int i = 0; i < N; i++)
		prefixSums[i] = A[i];
	for(int i = 1; i < N; i++) {
		prefixSums[i] += prefixSums[i-1];
	}


	int l = 0, r = N-1;


	int ans = 1000000;
	while(l <= r) {
		int mid = (l + r) / 2;

		ll res = prefixSums[mid];
		bool works = true;
		for(int i = mid + 1; i < N; i++) {
			if(res < A[i]) {
				works = false;
				break;
			}
			res += A[i];
		}

		if(!works) {
			l = mid + 1;
		} else {
			r = mid - 1;
			ans = mid;
		}
	}
	vector<int> B;


	for(int i = ans; i < N; i++) {
		pair<ll, ll> p = (*idx.lower_bound(make_pair(A[i], 0)));
		B.push_back(p.second);
		idx.erase(idx.find(p));
	}
	sort(B.begin(), B.end());

	cout << B.size() << "\n";
	for(auto &e: B)
		cout << e << " ";
	cout << "\n";



}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
   
    while(T--)
        solve();
}
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
vector<int> toRemove[200001];
void solve() {
	int N; cin >> N;
	map<int, int> freq;

	for(int i = 1; i <= N; i++) {
		toRemove[i].clear();
		toRemove[i].push_back(0);
	}

	vector<int> A(N);

	for(auto &a: A)
		cin >> a;


	

	
	for(int i = 0; i < N; i++) {
		toRemove[A[i]].push_back(i+1);
	}
	int mx = int(1e9);
	// int mx = *max_element(A.begin(), A.end());
	for(int i = 1; i <= N; i++) {
		toRemove[i].push_back(N + 1);
		if(toRemove[i].size() <= 2) continue;
		int p = toRemove[i].size();
		int cur = 0;
		for(int j = 1; j < p; j++) {
			if(toRemove[i][j]-toRemove[i][j-1] > 1) {
				cur++;
			} 
		}
		if(mx > cur) {
			// dbg(i, cur);
			mx = cur;
		}
	}

	cout << mx << "\n";


}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; cin >> T;
   
    while(T--)
        solve();
}
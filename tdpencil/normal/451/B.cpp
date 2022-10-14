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


	if(is_sorted(A.begin(), A.end())) {
		cout << "yes\n";
		cout << 1 << " " << 1 << "\n";
		return;
	}

	int p = -1;
	
	for(int i = 0; i < N-1; i++) {
		if(A[i] > A[i+1]) {
			p=i;
			break;
		}
	}


	int cur = p;
	// dbg(A);
	while(cur < N-1 && A[cur] > A[cur+1]) {
		cur++;
	}
	
	int s = cur;
	reverse(A.begin() + p, A.begin() + s + 1);
	// dbg(A);
	// dbg(p, s);
	if(is_sorted(A.begin(), A.end())) {
		cout << "yes\n";
		cout << p + 1 << " " << s + 1 << "\n";
		return;
	} else {
		cout << "no\n";
	}
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}
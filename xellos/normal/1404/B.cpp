// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, A, B, DA, DB;
		cin >> N >> A >> B >> DA >> DB;
		vector< vector<int> > G(N);
		for(int i = 0; i < N-1; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
		}
		if(2*DA >= DB) {
			cout << "Alice\n";
			continue;
		}
		vector<int> distB(N, -1);
		queue<int> q;
		q.push(--B);
		A--;
		distB[B] = 0;
		while(!q.empty()) {
			for(auto v : G[q.front()]) if(distB[v] == -1) {
				distB[v] = distB[q.front()]+1;
				q.push(v);
			}
			q.pop();
		}
		if(distB[A] <= DA) {
			cout << "Alice\n";
			continue;
		}
		int max_dist = 0;
		for(int i = 0; i < N; i++) max_dist = max(max_dist, distB[i]);
		int C = 0;
		for(int i = 0; i < N; i++) if(max_dist == distB[i]) C = i;
		vector<int> distC(N, -1);
		distC[C] = 0;
		q.push(C);
		while(!q.empty()) {
			for(auto v : G[q.front()]) if(distC[v] == -1) {
				distC[v] = distC[q.front()]+1;
				q.push(v);
			}
			q.pop();
		}
		int diam = 0;
		for(int i = 0; i < N; i++) diam = max(diam, distC[i]);
		if(diam <= 2*DA) {
			cout << "Alice\n";
			continue;
		}
		cout << "Bob\n";
	}
}

// look at my code
// my code is amazing
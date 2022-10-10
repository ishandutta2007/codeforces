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
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

int solve(vector< pair<int,int> > R[3]) {
	int N = R[0].size();
	for(int k = 0; k < 3; k++) sort(begin(R[k]), end(R[k]));
	priority_queue<int> Q[2];
	int ret = 0;
	for(int i = 0, a = 0, b = 0; i < N; i++) {
		while(a < N && R[0][a].ff < R[2][i].ff) {
			int x = R[0][a].ss;
			Q[0].push(x);
			a++;
		}
		while(b < N && R[1][b].ff < R[2][i].ff) {
			int x = R[1][b].ss;
			Q[1].push(-x);
			b++;
		}
		int k = N-i;
		while(Q[0].size() > k) Q[0].pop();
		while(Q[1].size() > k) Q[1].pop();
		if(Q[0].size() == k && Q[1].size() == k)
			if(Q[0].top() < -Q[1].top()) ret = max(ret, k);
	}
	int l = 0, r = N-1;
	for(int k = 1; k <= N; k++) {
		while(l <= r && R[0][k-1].ff >= R[1][l].ff) l++;
		while(l <= r && R[2][N-k].ff <= R[1][r].ff) r--;
		if(r-l+1 >= k) ret = max(ret, k);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	N /= 3;
	vector< pair<int,int> > P[3];
	for(int i = 0; i < 3*N; i++) {
		int x,y,c;
		cin >> x >> y >> c;
		P[c-1].push_back({x, y});
	}
	int ans = 0;
	for(int kt = 0; kt < 2; kt++) {
		for(int ke = 0; ke < 2; ke++) {
			for(int kf = 0; kf < 2; kf++) {
				for(int kc = 0; kc < 3; kc++) {
					vector< pair<int,int> > R[3];
					for(int i = 0; i < 3; i++) R[i] = P[(i+kc)%3];
					ans = max(ans, solve(R));
					swap(R[0], R[1]);
					ans = max(ans, solve(R));
				}
				for(int i = 0; i < 3; i++) for(int j = 0; j < N; j++) P[i][j].ss *= -1;
			}
			for(int i = 0; i < 3; i++) for(int j = 0; j < N; j++) P[i][j].ff *= -1;
		}
		for(int i = 0; i < 3; i++) for(int j = 0; j < N; j++) swap(P[i][j].ff, P[i][j].ss);
	}
	cout << 3*ans << "\n";
}

// look at my code
// my code is amazing
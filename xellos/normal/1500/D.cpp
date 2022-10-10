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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	vector< vector<int> > C(N, vector<int>(N));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		cin >> C[i][j];
		C[i][j]--;
	}
	vector< vector< vector< pair<int, int> > > > I(N+1, vector< vector< pair<int, int> > >(N+1));
	vector<char> used(N*N, 0);
	vector<int> ans(N, 0);
	for(int r = N-1; r >= 0; r--) for(int c = N-1; c >= 0; c--) {
		I[r][c].push_back({C[r][c], 0});
		used[C[r][c]] = 1;
		int sz = 1;
		int x = 0, y = 0, z = 0;
		int sz_x = I[r][c+1].size(), sz_y = I[r+1][c].size(), sz_z = I[r+1][c+1].size();
		while(true) {
			int a_min = N+1;
			if(x < sz_x) a_min = min(a_min, I[r][c+1][x].ss+1);
			if(y < sz_y) a_min = min(a_min, I[r+1][c][y].ss+1);
			if(z < sz_z) a_min = min(a_min, I[r+1][c+1][z].ss+1);
			if(a_min >= N-max(r,c)) break;
			while(x < sz_x && I[r][c+1][x].ss+1 == a_min) {
				if(!used[I[r][c+1][x].ff]) {
					I[r][c].push_back({I[r][c+1][x].ff, a_min});
					used[I[r][c+1][x].ff] = 1;
					sz++;
				}
				x++;
			}
			while(y < sz_y && I[r+1][c][y].ss+1 == a_min) {
				if(!used[I[r+1][c][y].ff]) {
					I[r][c].push_back({I[r+1][c][y].ff, a_min});
					used[I[r+1][c][y].ff] = 1;
					sz++;
				}
				y++;
			}
			while(z < sz_z && I[r+1][c+1][z].ss+1 == a_min) {
				if(!used[I[r+1][c+1][z].ff]) {
					I[r][c].push_back({I[r+1][c+1][z].ff, a_min});
					used[I[r+1][c+1][z].ff] = 1;
					sz++;
				}
				z++;
			}
			if(sz > Q) break;
		}
		for(auto p : I[r][c]) used[p.ff] = 0;
		int a_max = N-max(r,c);
		if(sz > Q) {
			I[r][c].resize(Q+1);
			a_max = I[r][c][Q].ss;
		}
		ans[a_max-1]++;
	}
	for(int i = N-1; i > 0; i--) ans[i-1] += ans[i];
	for(int i = 0; i < N; i++) cout << ans[i] << "\n";
}

// look at my code
// my code is amazing
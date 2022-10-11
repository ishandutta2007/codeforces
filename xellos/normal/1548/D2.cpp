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
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	int cnt_p[4][4];
	memset(cnt_p, 0, sizeof(cnt_p));
	for(int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		cnt_p[X[i]%4][Y[i]%4]++;
	}
	cat ans = 0;
	for(int m = 0; m < 4; m++) {
		// all x have parity m/2, all y have parity m%2
		for(int k = 0; k < 4; k++) {
			cat c = cnt_p[(k/2)*2+(m/2)][(k%2)*2+(m%2)];
			ans += c * (c-1) * (c-2) / 6;
		}
		for(int k = 0; k < 4; k++) {
			cat c = cnt_p[(k/2)*2+(m/2)][(k%2)*2+(m%2)];
			ans += c * (c-1) / 2 * cnt_p[(k/2)*2+(m/2)][(1-k%2)*2+(m%2)];
			ans += c * (c-1) / 2 * cnt_p[(1-k/2)*2+(m/2)][(k%2)*2+(m%2)];
			ans += c * (c-1) / 2 * cnt_p[(1-k/2)*2+(m/2)][(1-k%2)*2+(m%2)];
		}
	}
	vector< vector<int> > G(N, vector<int>(N));
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++)
		if((X[i]-X[j])%2 || (Y[i]-Y[j])%2)
			G[i][j] = G[j][i] = gcd(abs(X[i]-X[j]), abs(Y[i]-Y[j]));
	for(int i = 0; i < N; i++) for(int xd = 0; xd < 2; xd++) for(int yd = 0; yd < 2; yd++) if(xd+yd) {
		int cnt[2][2][2] = {{{0,0},{0,0}},{{0,0},{0,0}}};
		for(int j = 0; j < N; j++) if((X[j]-X[i]-xd)%2 == 0 && (Y[j]-Y[i]-yd)%2 == 0) {
			int x = (X[j]-X[i])%4;
			if(x < 0) x += 4;
			int y = (Y[j]-Y[i])%4;
			if(y < 0) y += 4;
			cnt[G[i][j]/2%2][x/2%2][y/2%2]++;
		}
		for(int x = 0; x < 4; x++) for(int y = 0; y < 4; y++) for(int g = 0; g < 4; g++) {
			int id1 = (g/2)*4+(x/2)*2+(y/2);
			int id2 = (g%2)*4+(x%2)*2+(y%2);
			if(id1 > id2) continue;
			cat cnt1 = cnt[g/2][x/2][y/2];
			cat cnt_tot = (id1 == id2) ? cnt1*(cnt1-1)/2 : (cnt1*cnt[g%2][x%2][y%2]);
			int lhs = (g/2*2+1) + (g%2*2+1) + ((x/2 == x%2 && y/2 == y%2) ? 0 : 2);
			int rhs = (x/2*2+xd) * (y%2*2+yd) - (x%2*2+xd) * (y/2*2+yd);
			if((lhs-rhs)%4 == 0) ans += cnt_tot;
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing
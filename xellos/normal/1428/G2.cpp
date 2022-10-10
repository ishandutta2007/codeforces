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
	cat P;
	cat F[6];
	cin >> P >> F[0] >> F[1] >> F[2] >> F[3] >> F[4] >> F[5];

	int MX = 1;
	vector<cat> val(1000000, -OVER9000);
	val[0] = 0;
	for(int d = 5; d >= 0; d--) {
		deque< pair<cat, int> > q[3];
		vector<cat> val_tmp(MX*10, -OVER9000);
		for(int i = 0; i < MX*10; i++) {
			int id = i%3;
			if(i%10 == 0) {
				while(!q[id].empty() && q[id].front().ff <= val[i/10]-i*F[d])
					q[id].pop_front();
				q[id].push_front({val[i/10]-i*F[d], i});
			}
			while(!q[id].empty() && i-q[id].back().ss > 9*(P-1)) q[id].pop_back();
			if(!q[id].empty()) val_tmp[i] = i*F[d] + q[id].back().ff;
		}
		for(int i = 0; i < MX*10; i++) {
			val[i] = -OVER9000;
			for(int k = 0; k <= min(i, 9); k++) val[i] = max(val[i], val_tmp[i-k]);
			for(int k = 0; k <= min(i, 9); k += 3) val[i] = max(val[i], val_tmp[i-k] + k * F[d]);
		}
		MX *= 10;
	}

	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		int S;
		cin >> S;
		cout << val[S]/3 << "\n";
	}
}

// look at my code
// my code is amazing
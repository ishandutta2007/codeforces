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

dbl norm(dbl a) {
	while(a < -pi) a += 2*pi;
	while(a > pi-soclose) a -= 2*pi;
	return a;
}

struct ray {
	dbl ang;
	int tp, id;

	bool operator<(const ray & r) const {
		return ang < r.ang-soclose;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cat R;
	cin >> N >> R;
	vector<cat> X(N), Y(N);
	for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	vector< vector<char> > B(N, vector<char>(N, 0));
	for(int k = 0; k < N; k++) {
		vector<ray> A;
		A.dibs(3*(N-1));
		int cur = 0;
		for(int i = 0; i < N; i++) if(i != k) {
			cat dx = X[i]-X[k], dy = Y[i]-Y[k];
			cat l2 = dx*dx+dy*dy;
			dbl angc = atan2(dy,dx);
			A.push_back(ray{.ang = norm(angc), .tp = 0, .id = i});
			if(R*R >= l2) {
				cur++;
				continue;
			}
			dbl angd = asin(dbl(R)/sqrt(l2));
			A.push_back(ray{.ang = norm(angc-angd), .tp = 1, .id = i});
			A.push_back(ray{.ang = norm(angc+angd), .tp = 2, .id = i});
			if(angc-angd < -pi+soclose || angc+angd > pi-soclose) cur++;
		}
		sort(begin(A), end(A));
		for(auto r : A) {
			if(r.tp == 0) B[k][r.id] = (cur == N-1);
			else if(r.tp == 1) cur++;
			else if(r.tp == 2) cur--;
		}
	}
	cat ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) ans += B[i][j] & B[j][i];
	cout << ans << "\n";
}

// look at my code
// my code is amazing
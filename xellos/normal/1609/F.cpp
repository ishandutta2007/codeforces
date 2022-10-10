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
class fin_range {
	struct lin {
		T a, c;

		lin() : a{0}, c{0} {}
		lin(T a_, T c_) : a{a_}, c{c_} {}

		lin & operator+=(lin & l) {
			this->a += l.a;
			this->c += l.c;
			return *this;
		}
	};

	T sum;
	vector<lin> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin_range() = default;
	fin_range(int N) : sum{0} { node_val.resize(N+10); }

	void add(int pos, T val) {
		if(pos == 0) return;
		sum += val;
		lin l(-val, pos*val);
		for(int i = pos; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += l;
	}

	T get(int pos) {
		lin l(sum, 0);
		for(int i = pos; i > 0; i -= lastone(i))
			l += node_val[i];
		return pos * l.a + l.c;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> B(N);
	for(int i = 0; i < N; i++) B[i] = __builtin_popcountll(A[i]);
	cat ans = 0;
	constexpr int bd = 15;
	for(int bp = 0; bp < 60; bp += bd) {
		fin_range<int> F[2][bd];
		cat cur[bd];
		for(int k = 0; k < 2*bd; k++) {
			F[k/bd][k%bd] = fin_range<int>(N);
			cur[k%bd] = 0;
		}
		vector<int> seq_mx = {-1}, seq_mi = {-1};
		for(int i = 0; i < N; i++) {
			while(seq_mx.back() != -1 && A[seq_mx.back()] <= A[i]) {
				int r = seq_mx.back() + 1;
				seq_mx.pop_back();
				int l = seq_mx.back() + 1;
				if(B[r-1] >= bp && B[r-1] < bp+bd) {
					int br = B[r-1]%bd;
					cur[br] -= F[0][br].get(r) - F[0][br].get(l);
					F[1][br].add(r, -1);
					F[1][br].add(l, 1);
				}
			}
			if(B[i] >= bp && B[i] < bp+bd) {
				int br = B[i]%bd;
				int l = seq_mx.back()+1, r = i+1;
				cur[br] += F[0][br].get(r) - F[0][br].get(l);
				F[1][br].add(r, 1);
				F[1][br].add(l, -1);
			}
			seq_mx.push_back(i);
			while(seq_mi.back() != -1 && A[seq_mi.back()] >= A[i]) {
				int r = seq_mi.back() + 1;
				seq_mi.pop_back();
				int l = seq_mi.back() + 1;
				if(B[r-1] >= bp && B[r-1] < bp+bd) {
					int br = B[r-1]%bd;
					cur[br] -= F[1][br].get(r) - F[1][br].get(l);
					F[0][br].add(r, -1);
					F[0][br].add(l, 1);
				}
			}
			if(B[i] >= bp && B[i] < bp+bd) {
				int br = B[i]%bd;
				int l = seq_mi.back()+1, r = i+1;
				cur[br] += F[1][br].get(r) - F[1][br].get(l);
				F[0][br].add(r, 1);
				F[0][br].add(l, -1);
			}
			seq_mi.push_back(i);
			for(int k = 0; k < bd; k++) ans += cur[k];
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing
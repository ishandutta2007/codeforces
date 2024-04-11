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

struct itree {
	int b;
	vector<int> valA, valC, addA, addC, valM;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		valA.resize(2*b, 0);
		valC.resize(2*b, 0);
		valM.resize(2*b, 0);
		addA.resize(2*b, 0);
		addC.resize(2*b, 0);
	}

	void upd(int cur, int l, int r) {
		valA[cur] += addA[cur];
		valC[cur] += addC[cur];
		valM[cur] += addA[cur]+addC[cur];
		if(l+1 < r) {
			addA[2*cur] += addA[cur], addA[2*cur+1] += addA[cur];
			addC[2*cur] += addC[cur], addC[2*cur+1] += addC[cur];
		}
		addA[cur] = addC[cur] = 0;
	}

	void putA(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			addA[cur] += val;
			upd(cur, l, r);
			return;
		}
		upd(cur, l, r);
		if(I_l >= I_r) return;
		int m = (l+r)/2;
		putA(I_l, I_r, val, 2*cur, l, m);
		putA(I_l, I_r, val, 2*cur+1, m, r);
		valM[cur] = min(min(valM[2*cur], valM[2*cur+1]), valA[2*cur]+valC[2*cur+1]);
		valA[cur] = min(valA[2*cur], valA[2*cur+1]);
		valC[cur] = min(valC[2*cur], valC[2*cur+1]);
	}

	void putC(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			addC[cur] += val;
			upd(cur, l, r);
			return;
		}
		upd(cur, l, r);
		if(I_l >= I_r) return;
		int m = (l+r)/2;
		putC(I_l, I_r, val, 2*cur, l, m);
		putC(I_l, I_r, val, 2*cur+1, m, r);
		valM[cur] = min(min(valM[2*cur], valM[2*cur+1]), valA[2*cur]+valC[2*cur+1]);
		valA[cur] = min(valA[2*cur], valA[2*cur+1]);
		valC[cur] = min(valC[2*cur], valC[2*cur+1]);
	}

	int get() {
		upd(1, 0, b);
		return valM[1];
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	string S;
	cin >> N >> Q >> S;
	int nA = 0, nB = 0, nC = 0;
	itree I(1<<17);
	for(int i = 0; i < N; i++) {
		int pos = i;
		if(S[pos] == 'a') {
			nA++;
			I.putA(pos+1, 1<<17, +1);
		}
		if(S[pos] == 'b') {
			nB++;
			I.putA(pos+1, 1<<17, -1);
			I.putC(0, pos+1, -1);
		}
		if(S[pos] == 'c') {
			nC++;
			I.putC(0, pos+1, +1);
		}
	}
	for(int q = 0; q < Q; q++) {
		int pos;
		string c;
		cin >> pos >> c;
		pos--;
		if(S[pos] == 'a') {
			nA--;
			I.putA(pos+1, 1<<17, -1);
		}
		if(S[pos] == 'b') {
			nB--;
			I.putA(pos+1, 1<<17, +1);
			I.putC(0, pos+1, +1);
		}
		if(S[pos] == 'c') {
			nC--;
			I.putC(0, pos+1, -1);
		}
		S[pos] = c[0];
		if(S[pos] == 'a') {
			nA++;
			I.putA(pos+1, 1<<17, +1);
		}
		if(S[pos] == 'b') {
			nB++;
			I.putA(pos+1, 1<<17, -1);
			I.putC(0, pos+1, -1);
		}
		if(S[pos] == 'c') {
			nC++;
			I.putC(0, pos+1, +1);
		}
		cout << min(min(nA,nC),nB+I.get()) << "\n";
	}
}

// look at my code
// my code is amazing
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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, K;
	cin >> N >> K;
	if(N <= 150) {
		set<int> cand;
		for(int i = 0; i < N; i++) cand.insert(i);
		vector<int> A(N, K);
		for(int i = 0; i < 1000; i++) {
			cout << "? " << i%N+1 << endl;
			int a;
			cin >> a;
			set<int> cand_nw;
			for(auto x : cand) if(A[(N-x+i)%N] == a) cand_nw.insert(x);
			cand = cand_nw;
			vector<int> A_nw(N, 0);
			A_nw[1] += A[0];
			for(int j = 1; j < N; j++) {
				A_nw[j-1] += A[j]/2;
				A_nw[(j+1)%N] += A[j]-A[j]/2;
			}
			A = A_nw;
			if(cand.size() == 1) break;
		}
		cout << "! " << *begin(cand)+1 << endl;
		return 0;
	}
	int S = 0;
	while(S*S < N) S++;
	int cur, i;
	for(i = 0; i < 1000; i++) {
		cur = i*S%N;
		cout << "? " << cur+1 << endl;
		int a;
		cin >> a;
		if(i > S+1 && a != K) break;
	}
	while(true) {
		cur -= 2;
		if(cur < 0) cur += N;
		i++;
		cout << "? " << cur+1 << endl;
		int a;
		cin >> a;
		if(a == K) break;
	}
	// step i: A[cur] == K, A[cur+1] == K-1, cur+1 == ans-i
	cout << "! " << (cur+1+i)%N+1 << endl;
}

// look at my code
// my code is amazing
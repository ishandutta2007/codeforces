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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<cat> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector<cat> B;
		for(int i = 1; i < N-1; i++) if(A[i]) B.push_back(A[i]);
		int M = B.size();
		if(M == 1 && B[0]%2) {
			cout << "-1\n";
			continue;
		}
		int has_ge2 = false;
		for(int i = 0; i < M; i++) if(B[i] >= 2) has_ge2 = true;
		if(!has_ge2) {
			cout << "-1\n";
			continue;
		}
		vector<int> odd_id;
		for(int i = 0; i < M; i++) if(B[i]%2) odd_id.push_back(i);
		cat ans = odd_id.size();
		if(!odd_id.empty()) {
			for(int i = odd_id[0]+1; i < odd_id[odd_id.size()-1]; i++) if(B[i] >= 2)
				ans = odd_id.size() - odd_id.size()/2;
		}
		cat s = 0;
		for(int i = 0; i < M; i++) s += B[i];
		if(ans == odd_id.size()) s -= odd_id.size();
		else s -= odd_id.size()%2;
		ans += s/2;
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing
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
		int A[4];
		string S;
		cin >> A[0] >> A[1] >> A[2] >> A[3] >> S;
		int n[2] = {0, 0};
		int N = S.length();
		for(int i = 0; i < N; i++) {
			if(S[i] == 'A') n[0]++;
			else n[1]++;
		}
		if(n[0] != A[0]+A[2]+A[3] || n[1] != A[1]+A[2]+A[3]) {
			cout << "NO\n";
			continue;
		}
		vector<int> L[2];
		int l0 = 0;
		for(int i = 0; i < N; i++) if(i == 0 || S[i] == S[i-1]) {
			int r = i+1;
			while(r < N && S[r] != S[r-1]) r++;
			if((r-i)%2 != 0) l0 += (r-i)/2;
			else L[S[i]=='B'].push_back((r-i)/2);
		}
		sort(begin(L[0]), end(L[0]));
		sort(begin(L[1]), end(L[1]));
		bool ans = false;
		int s0 = 0, s1 = 0;
		for(auto l : L[0]) s0 += l-1;
		for(auto l : L[1]) s1 += l-1;
		int x0 = 0, x1 = 0, p0 = 0, p1 = 0;
		for(int i = 0, s0l = 0, s0r = s0; i <= (int)L[0].size(); i++) {
			if(i > 0) s0l += L[0][i-1], s0r -= L[0][i-1]-1;
			if(s0l >= A[2]) {
				if(s1+L[1].size()+l0+s0r >= A[3]) ans = true;
				break;
			}
			x0 = i;
			p0 = s0l;
		}
		for(int i = 0, s1l = 0, s1r = s1; i <= (int)L[1].size(); i++) {
			if(i > 0) s1l += L[1][i-1], s1r -= L[1][i-1]-1;
			if(s1l >= A[3]) {
				if(s0+L[0].size()+l0+s1r >= A[2]) ans = true;
				break;
			}
			x1 = i;
			p1 = s1l;
		}
		for(int i = x0; i < (int)L[0].size(); i++) l0 += L[0][i]-1;
		for(int i = x1; i < (int)L[1].size(); i++) l0 += L[1][i]-1;
		// p0+i >= A[2], p1+j >= A[3], i+j <= l0
		// p0 <= A[2], p1 <= A[3]
		if(A[2]-p0+A[3]-p1 <= l0) ans = true;
		cout << (ans ? "YES\n" : "NO\n");
	}
}

// look at my code
// my code is amazing
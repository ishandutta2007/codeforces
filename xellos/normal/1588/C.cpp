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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<cat> A(N);
		cat sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			sum += A[i];
		}
		A.push_back(sum+1);
		N++;
		vector<cat> S2(N, 0);
		for(int i = 0; i < N; i++) {
			if(i < 2) S2[i] = A[i];
			else S2[i] = S2[i-2]+A[i];
		}
		vector< pair<cat,int> > B, C;
		vector<int> R(N, N);
		for(int l = N-2; l >= 0; l -= 2) {
			int r = N;
			while(!B.empty() && B.back().ff <= S2[l]-S2[l+1]) B.pop_back();
			B.push_back({S2[l]-S2[l+1], l+1});
			int b_le = -1, b_gt = B.size();
			while(b_gt-b_le > 1) {
				int b = (b_le + b_gt);
				if(B[b].ff > -S2[l+1]+A[l+1]+S2[l]-A[l]) b_le = b;
				else b_gt = b;
			}
			if(b_le != -1) r = min(r, B[b_le].ss);
			if(l+2 < N) {
				while(!C.empty() && C.back().ff >= S2[l+2]-S2[l+1]) C.pop_back();
				C.push_back({S2[l+2]-S2[l+1], l+2});
			}
			int c_le = -1, c_gt = C.size();
			while(c_gt-c_le > 1) {
				int c = (c_le + c_gt);
				if(C[c].ff < -S2[l+1]+A[l+1]+S2[l]-A[l]) c_le = c;
				else c_gt = c;
			}
			if(c_le != -1) r = min(r, C[c_le].ss);
			R[l] = r;
		}
		B.clear(), C.clear();
		for(int l = N-3; l >= 0; l -= 2) {
			int r = N;
			while(!B.empty() && B.back().ff <= S2[l]-S2[l+1]) B.pop_back();
			B.push_back({S2[l]-S2[l+1], l+1});
			int b_le = -1, b_gt = B.size();
			while(b_gt-b_le > 1) {
				int b = (b_le + b_gt);
				if(B[b].ff > -S2[l+1]+A[l+1]+S2[l]-A[l]) b_le = b;
				else b_gt = b;
			}
			if(b_le != -1) r = min(r, B[b_le].ss);
			if(l+2 < N) {
				while(!C.empty() && C.back().ff >= S2[l+2]-S2[l+1]) C.pop_back();
				C.push_back({S2[l+2]-S2[l+1], l+2});
			}
			int c_le = -1, c_gt = C.size();
			while(c_gt-c_le > 1) {
				int c = (c_le + c_gt);
				if(C[c].ff < -S2[l+1]+A[l+1]+S2[l]-A[l]) c_le = c;
				else c_gt = c;
			}
			if(c_le != -1) r = min(r, C[c_le].ss);
			R[l] = r;
		}
		map<cat,int> lastB[2], lastC[2];
		vector<int> ans(N, 0);
		cat ans_sum = 0;
		for(int l = N-1; l >= 0; l--) {
			if(l < N-1) lastB[l&1][S2[l]-S2[l+1]] = l+2;
			if(l < N-2) lastC[l&1][S2[l+2]-S2[l+1]] = l+3;
			int r_good = N+1;
			if(A[l] == 0) r_good = l+1;
			else if(l < N-1) {
				auto it = lastB[l&1].find(-S2[l+1]+A[l+1]+S2[l]-A[l]);
				if(it != end(lastB[l&1])) r_good = min(r_good, it->ss);
				auto jt = lastC[l&1].find(-S2[l+1]+A[l+1]+S2[l]-A[l]);
				if(jt != end(lastC[l&1])) r_good = min(r_good, jt->ss);
			}
			if(r_good > R[l]) continue;
			ans[l] = ans[r_good]+1;
			ans_sum += ans[l];
		}
		cout << ans_sum << "\n";
	}
}

// look at my code
// my code is amazing
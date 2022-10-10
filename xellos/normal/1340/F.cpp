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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

constexpr cat mod = 1000000007;
constexpr cat p = 999983;
vector<cat> pw;

struct H {
	int L_l, L_r;
	vector<cat> B_l, B_r;

	void init(vector<int> st) {
		B_l.resize(L_l+1, 0);
		for(int j = 0; j < L_l; j++)
			B_l[j+1] = (B_l[j] * p - st[L_l-1-j]) % mod;
		B_r.resize(L_r+1, 0);
		for(int j = 0; j < L_r; j++)
			B_r[j+1] = (B_r[j] * p + st[L_l+j]) % mod;
	}
};

bool check_equal(H & l, int st_l, H & r, int st_r, int d) {
	// l.B_r[st_l...st_l+d] == r.B_l[st_r...st_r+d]
	cat h_l = l.B_r[st_l+d] - l.B_r[st_l] * pw[d];
	cat h_r = r.B_l[st_r+d] - r.B_l[st_r] * pw[d];
	if((h_l-h_r) % mod) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, K, Q;
	cin >> N >> K;
	vector<int> A(N, 0);
	for(int i = 0; i < N; i++) cin >> A[i];
	pw.resize(N+1, 1);
	for(int i = 1; i <= N; i++) pw[i] = pw[i-1] * p % mod;

	int L = 300;
	vector<char> ok(N/L+1, false);
	vector<H> B(N/L+1);
	vector<int> st;
	for(int i = 0; i < N; i += L) {
		int id = i/L;
		st.clear();
		ok[id] = true;
		for(int j = i; j < min(N, i+L); j++) {
			if(A[j] > 0) st.push_back(A[j]);
			else if(!st.empty() && st.back() > 0 && st.back() != -A[j]) {
				ok[id] = false;
				break;
			}
			else if(st.empty() || st.back() < 0) st.push_back(A[j]);
			else st.pop_back();
		}
		if(!ok[id]) continue;
		B[id].L_l = B[id].L_r = 0;
		int sz = st.size();
		while(B[id].L_l != sz && st[B[id].L_l] < 0) B[id].L_l++;
		while(B[id].L_r != sz && st[sz-1-B[id].L_r] > 0) B[id].L_r++;
		if(B[id].L_l+B[id].L_r != sz) {
			ok[id] = false;
			continue;
		}
		B[id].init(st);
	}

	cin >> Q;
	for(int i = 0; i < Q; i++) {
		int t, a, b;
		cin >> t >> a >> b;

		if(t == 1) {
			A[--a] = b;
			int id = a/L;
			st.clear();
			ok[id] = true;
			for(int j = id*L; j < min(N, id*L+L); j++) {
				if(A[j] > 0) st.push_back(A[j]);
				else if(!st.empty() && st.back() > 0 && st.back() != -A[j]) {
					ok[id] = false;
					break;
				}
				else if(st.empty() || st.back() < 0) st.push_back(A[j]);
				else st.pop_back();
			}
			if(!ok[id]) continue;
			B[id].L_l = B[id].L_r = 0;
			int sz = st.size();
			while(B[id].L_l != sz && st[B[id].L_l] < 0) B[id].L_l++;
			while(B[id].L_r != sz && st[sz-1-B[id].L_r] > 0) B[id].L_r++;
			if(B[id].L_l+B[id].L_r != sz) ok[id] = false;
			else B[id].init(st);
			continue;
		}

		a--;
		bool ans = true;
		if(b-a < 2*L) {
			st.clear();
			for(int j = a; j < b; j++) {
				if(A[j] > 0) st.push_back(A[j]);
				else if(st.empty() || st.back() != -A[j]) {
					ans = false;
					break;
				}
				else st.pop_back();
			}
			if(!st.empty()) ans = false;
			cout << (ans ? "Yes\n" : "No\n");
			continue;
		}

		int id_l = (a+L-1)/L, id_r = b/L;
		for(int j = id_l; j < id_r; j++) if(!ok[j]) {
			ans = false;
			break;
		}
		if(!ans) {
			cout << "No\n";
			continue;
		}

		static vector<int> st_l;
		st_l.clear();
		for(int j = a; j < id_l*L; j++) {
			if(A[j] > 0) st_l.push_back(A[j]);
			else if(!st_l.empty() && st_l.back() > 0 && st_l.back() != -A[j]) {
				ans = false;
				break;
			}
			else if(st_l.empty() || st_l.back() < 0) st_l.push_back(A[j]);
			else st_l.pop_back();
		}
		if(!ans) {
			cout << "No\n";
			continue;
		}
		static vector<int> st_r;
		st_r.clear();
		for(int j = id_r*L; j < b; j++) {
			if(A[j] > 0) st_r.push_back(A[j]);
			else if(!st_r.empty() && st_r.back() > 0 && st_r.back() != -A[j]) {
				ans = false;
				break;
			}
			else if(st_r.empty() || st_r.back() < 0) st_r.push_back(A[j]);
			else st_r.pop_back();
		}
		if(!ans) {
			cout << "No\n";
			continue;
		}
		static H B_l;
		B_l.L_l = B_l.L_r = 0;
		int sz = st_l.size();
		while(B_l.L_l != sz && st_l[B_l.L_l] < 0) B_l.L_l++;
		while(B_l.L_r != sz && st_l[sz-1-B_l.L_r] > 0) B_l.L_r++;
		if(B_l.L_l+B_l.L_r != sz) {
			cout << "No\n";
			continue;
		}
		static H B_r;
		B_r.L_l = B_r.L_r = 0;
		sz = st_r.size();
		while(B_r.L_l != sz && st_r[B_r.L_l] < 0) B_r.L_l++;
		while(B_r.L_r != sz && st_r[sz-1-B_r.L_r] > 0) B_r.L_r++;
		if(B_r.L_l+B_r.L_r != sz) {
			cout << "No\n";
			continue;
		}
		B_l.init(st_l);
		B_r.init(st_r);
		H * P[10000];
		P[0] = &B_l;
		for(int j = id_l; j < id_r; j++) P[1+j-id_l] = &(B[j]);
		P[1+id_r-id_l] = &B_r;

		static vector< pair<H *, int> > O;
		O.clear();
		for(int j = 0; j <= 1+id_r-id_l; j++) {
			int sz_cl = P[j]->L_l;
			while(sz_cl) {
				if(O.empty()) {
					ans = false;
					break;
				}
				int d = min(sz_cl, O.back().ss);
				O.back().ss -= d;
				sz_cl -= d;
				if(!check_equal(*O.back().ff, O.back().ss, *P[j], sz_cl, d)) {
					ans = false;
					break;
				}
				if(O.back().ss == 0) O.pop_back();
			}
			if(!ans) break;
			if(P[j]->L_r) O.push_back({P[j], P[j]->L_r});
		}
		if(!O.empty()) ans = false;
		cout << (ans ? "Yes\n" : "No\n");
	}
	return 0;
}

// look at my code
// my code is amazing
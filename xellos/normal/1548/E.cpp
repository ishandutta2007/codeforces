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

template <typename T>
class maxfin {
	vector<T> node_val;
	int init_val_;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	maxfin(int N, T init_val) : init_val_{init_val} {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = max(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val_;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = max(ret, node_val[i]);
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> A(N+2, X+1);
	for(int i = 0; i < N; i++) cin >> A[i+1];
	vector<int> B(M+2, X+1);
	for(int i = 0; i < M; i++) cin >> B[i+1];
	N += 2;
	M += 2;
	vector<int> C(N);
	{
		vector<int> prev_le(N, -1), next_lt(N, N);
		vector< pair<int,int> > st;
		for(int i = 0; i < N; i++) {
			while(!st.empty() && st.back().ff > A[i]) st.pop_back();
			if(!st.empty()) prev_le[i] = st.back().ss;
			st.push_back({A[i], i});
		}
		st.clear();
		for(int i = N-1; i >= 0; i--) {
			while(!st.empty() && st.back().ff >= A[i]) st.pop_back();
			if(!st.empty()) next_lt[i] = st.back().ss;
			st.push_back({A[i], i});
		}
		vector<int> max_lft(N, 0), max_rt(N, 0);
		maxfin F_lft(N, 0);
		for(int i = 0; i < N; i++) {
			F_lft.put(N-1-i, A[i]);
			max_lft[i] = F_lft.get(N-1-(prev_le[i]+1));
		}
		maxfin F_rt(N, 0);
		for(int i = N-1; i >= 0; i--) {
			F_rt.put(i, A[i]);
			max_rt[i] = F_rt.get(next_lt[i]-1);
		}
		for(int i = 0; i < N; i++) {
			if(max_lft[i] > A[i] && max_rt[i] > A[i])
				C[i] = X - min(max_lft[i], max_rt[i]) + 1;
			else C[i] = OVER9000;
		}
	}
	vector<int> D(M);
	{
		vector<int> prev_le(M, -1), next_lt(M, M);
		vector< pair<int,int> > st;
		for(int i = 0; i < M; i++) {
			while(!st.empty() && st.back().ff > B[i]) st.pop_back();
			if(!st.empty()) prev_le[i] = st.back().ss;
			st.push_back({B[i], i});
		}
		st.clear();
		for(int i = M-1; i >= 0; i--) {
			while(!st.empty() && st.back().ff >= B[i]) st.pop_back();
			if(!st.empty()) next_lt[i] = st.back().ss;
			st.push_back({B[i], i});
		}
		vector<int> max_lft(M, 0), max_rt(M, 0);
		maxfin F_lft(M, 0);
		for(int i = 0; i < M; i++) {
			F_lft.put(M-1-i, B[i]);
			max_lft[i] = F_lft.get(M-1-(prev_le[i]+1));
		}
		maxfin F_rt(M, 0);
		for(int i = M-1; i >= 0; i--) {
			F_rt.put(i, B[i]);
			max_rt[i] = F_rt.get(next_lt[i]-1);
		}
		for(int i = 0; i < M; i++) {
			if(max_lft[i] > B[i] && max_rt[i] > B[i])
				D[i] = X - min(max_lft[i], max_rt[i]) + 1;
			else D[i] = OVER9000;
		}
	}
	vector< pair<int,int> > pts_Y;
	for(int i = 0; i < M; i++) if(D[i] < OVER9000) pts_Y.push_back({D[i], B[i]});
	sort(begin(pts_Y), end(pts_Y));
	vector< pair<int,int> > pts_X;
	for(int i = 0; i < N; i++) if(C[i] < OVER9000) pts_X.push_back({A[i], C[i]});
	sort(begin(pts_X), end(pts_X));
	fin F(200001, 0);
	cat ans = 0;
	for(int i = 0, j = 0; i < (int)pts_X.size(); i++) {
		while(j < (int)pts_Y.size() && pts_Y[j].ff <= pts_X[i].ff) {
			F.put(pts_Y[j].ss, 1);
			j++;
		}
		if(pts_X[i].ff > X) continue;
		ans += F.get(X-pts_X[i].ff) - F.get(max(0,pts_X[i].ss)-1);
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing
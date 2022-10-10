#pragma GCC optimize("O3")
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
	int N, Q;
	cin >> N;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> P(N);
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		P[i]--;
	}
	cin >> Q;
	vector<int> qs(Q*3);
	for(int i = 0; i < Q; i++) cin >> qs[3*i] >> qs[3*i+1] >> qs[3*i+2];
	constexpr int QD = 800;
	for(int qp = 0; qp < Q; qp += QD) {
		int qr = min(Q, qp+QD);
		vector<char> used(N, 0);
		for(int i = qp; i < qr; i++) {
			if(qs[3*i] == 3) {
				used[--qs[3*i+1]] = 1;
				used[--qs[3*i+2]] = 1;
			}
			if(qs[3*i] == 2)
				used[--qs[3*i+1]] = 1;
		}
		auto P_init = P;
		static vector< pair<int,int> > paths;
		paths.clear();
		vector<short> path_id(N, -1);
		for(int i = 0; i < N; i++) if(used[i]) {
			int cur = P_init[i];
			static vector<int> tmp;
			tmp.clear();
			while(!used[cur]) {
				tmp.push_back(cur);
				cur = P_init[cur];
			}
			tmp.push_back(cur);
			for(auto v : tmp) path_id[v] = paths.size();
			paths.push_back({P_init[i], cur});
		}
		int M = paths.size();
		vector<cat> sum(N+1, 0);
		for(int i = 0; i < N; i++) sum[i+1] = sum[i] + A[i];
		vector<cat> path_add(M, 0);
		vector<short> lim_gr(N+1, -1);
		lim_gr[N] = -2;
		for(int i = qp; i < qr; i++) if(qs[3*i] == 1)
			lim_gr[--qs[3*i+1]] = lim_gr[qs[3*i+2]] = -2;
		int L = 0;
		for(int i = 0; i <= N; i++) if(lim_gr[i] == -2) {
			for(int j = i; j >= 0; j--) {
				if(lim_gr[j] < 0) lim_gr[j] = L;
				else break;
			}
			L++;
		}
		static int cnt[QD*2][QD*2];
		memset(cnt, 0, M*QD*2*sizeof(int));
		for(int i = 0; i < N; i++) if(path_id[i] != -1) cnt[path_id[i]][lim_gr[i+1]]++;
		for(int i = 0; i < M; i++) for(int j = 1; j < L; j++) cnt[i][j] += cnt[i][j-1];
		for(int i = qp; i < qr; i++) {
			if(qs[3*i] == 3) {
				swap(P[qs[3*i+1]], P[qs[3*i+2]]);
				continue;
			}
			if(qs[3*i] == 2) {
				int cur = qs[3*i+1];
				int id_st = path_id[cur];
				while(true) {
					int id = path_id[cur];
					path_add[id] += qs[3*i+2];
					cur = P[paths[id].ss];
					if(path_id[cur] == id_st) break;
				}
				continue;
			}
			cat ans = sum[qs[3*i+2]]-sum[qs[3*i+1]];
			int l = lim_gr[qs[3*i+1]], r = lim_gr[qs[3*i+2]];
			for(int j = 0; j < M; j++)
				ans += path_add[j] * (cnt[j][r] - cnt[j][l]);
			cout << ans << "\n";
		}
		for(int i = 0; i < N; i++) if(path_id[i] >= 0) A[i] += path_add[path_id[i]];
	}
}

// look at my code
// my code is amazing
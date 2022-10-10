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
		int N,K;
		cin >> N >> K;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		if(K >= N) {
			cout << "0\n";
			continue;
		}
		sort(begin(A), end(A));
		// if(K == 0 && A[0] > 0) {
		// 	int dif = 1;
		// 	for(int i = 1; i < N; i++) if(A[i] != A[i-1]) dif++;
		// 	cout << dif << "\n";
		// 	continue;
		// }
		vector<int> miss(N+1, 1);
		for(int i = 0; i < N; i++) if(A[i] < N) miss[A[i]] = 0;
		for(int i = 0, m = 0; i <= N; i++) {
			int m_nw = m+miss[i];
			miss[i] = m;
			m = m_nw;
		}
		map<int,int> cnt;
		int X = 300;
		vector<int> cnt_lo(X+1, 0);
		multiset<int> cnt_hi;
		int ans = N;
		for(int mex = N, i = N-1, dif = 0; mex >= 0; mex--) {
			// >= mex
			// vyrob miss[mex], vsetky hodnoty < mex
			// min. pocet hodnot >= mex
			// ak je ich < K: ans=0
			while(i >= 0 && A[i] >= mex) {
				if(i == N-1 || A[i+1] > A[i]) dif++;
				auto it = cnt.find(A[i]);
				if(it == end(cnt)) {
					cnt[A[i]] = 1;
					cnt_lo[1]++;
				}
				else {
					if(it->ss <= X) cnt_lo[it->ss]--;
					else cnt_hi.erase(cnt_hi.find(it->ss));
					it->ss++;
					if(it->ss <= X) cnt_lo[it->ss]++;
					else cnt_hi.insert(it->ss);
				}
				i--;
			}
			if(miss[mex] > K) continue;
			// najdi v usortenom poli prvy bod kde sum > K
			int cnt_rm = 0, v_nxt = 0, s = 0;
			while(v_nxt <= X && cnt_lo[v_nxt]*v_nxt+s <= K) {
				s += cnt_lo[v_nxt] * v_nxt;
				cnt_rm += cnt_lo[v_nxt];
				v_nxt++;
			}
			if(v_nxt <= X) {
				cnt_rm += (K-s)/v_nxt;
				s += (K-s)/v_nxt*v_nxt;
			}
			else {
				for(auto c : cnt_hi) {
					if(s+c > K) break;
					cnt_rm++;
					s += c;
				}
			}
			ans = min(ans, dif-cnt_rm);
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing
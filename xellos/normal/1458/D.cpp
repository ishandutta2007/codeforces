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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		int N = S.length();
		vector<int> dif(N+1, 0);
		for(int i = 0; i < N; i++) dif[i+1] = dif[i] + ((S[i] == '0') ? -1 : 1);
		vector<int> next_occ(N+1, -1), next_occ_val(2*N+1, -1);
		for(int i = N; i >= 0; i--) {
			next_occ[i] = next_occ_val[dif[i]+N];
			next_occ_val[dif[i]+N] = i;
		}
		vector<int> cnt_dif_all(2*N+1, 0), cnt_dif(2*N+1, 0);
		for(int i = 0; i <= N; i++) cnt_dif_all[dif[i]+N]++;
		string ans;
		for(int k = 1, l = 0, r = max(0, next_occ[0]); k <= N; k++) {
			r = max(r, next_occ[k]);
			if(r > k) continue;
			r = k;
			for(int i = l; i <= r; i++) cnt_dif[dif[i]+N]++;
			int tot = dif[r];
			int cur = dif[l]-(r-l), n0end = 0;
			while(n0end < r-l) {
				while(cnt_dif[N+cur] == 0) cur++;
				if(cur == tot) {
					n0end++;
					cnt_dif[cur+N]--;
					tot++;
				}
				else break;
			}
			if(n0end < r-l) {
				for(int i = 0; i < -(cur-dif[l]); i++) ans += "0";
				for(int i = 0; i >= cur-dif[l]; i--) cnt_dif[i+dif[l]+N]--;
				for(int i = r-l; i >= cur-dif[l]; i--) if(cnt_dif[i+dif[l]+N]) {
					while(tot != i+dif[l]) {
						cnt_dif[tot+N]--;
						n0end++;
						tot++;
					}
					break;
				}
			}
			while((int)ans.length() < r-n0end) {
				if(cnt_dif[cur+N] == 0) {
					ans += "1";
					cur++;
					cnt_dif[cur+N]--;
					continue;
				}
				ans += "10";
				cnt_dif[cur+N]--;
				cnt_dif[cur+1+N]--;
			}
			for(int i = 0; i < n0end; i++) ans += "0";
			for(int i = l; i <= r; i++) cnt_dif[dif[i]+N] = 0;
			l = k;
			r = next_occ[k];
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing
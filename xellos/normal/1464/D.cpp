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
#define soclose 1e-9
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

int cost3(int * cnt) {
	if(cnt[1]+cnt[4] >= cnt[2]) return cnt[4]+cnt[2]+(cnt[4]+cnt[1]-cnt[2])/3*2;
	else return cnt[4]+(cnt[4]+cnt[1])+(cnt[2]-cnt[4]-cnt[1])/3*3;
}

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
		vector<int> P(N);
		for(int i = 0; i < N; i++) {
			cin >> P[i];
			P[i]--;
		}
		int cost_init = 0;
		int cnt[5] = {0, 0, 0, 0, 0};
		vector<char> vis(N, 0);
		for(int i = 0; i < N; i++) if(!vis[i]) {
			int cur = i, l = 0;
			while(!vis[cur]) {
				vis[cur] = 1;
				cur = P[cur];
				l++;
			}
			while(l >= 5) {
				l -= 3;
				cnt[3]++;
				cost_init++;
			}
			cnt[l]++;
		}
		cat max_days, mod = 1000000007;
		int ans = N+1;
		if(N%3 == 0) {
			max_days = 1;
			for(int i = 0; i < N/3; i++) max_days = max_days * 3 % mod;
			ans = min(ans, cost_init + cost3(cnt));
		}
		if(N%3 == 2) {
			max_days = 2;
			for(int i = 0; i < N/3; i++) max_days = max_days * 3 % mod;
			for(int k = 2; k <= 4; k++) if(cnt[k]) {
				cnt[k]--;
				cnt[k-2]++;
				ans = min(ans, cost_init + cost3(cnt) + (k != 2));
				cnt[k]++;
				cnt[k-2]--;
			}
			if(cnt[1] >= 2) {
				cnt[1] -= 2;
				ans = min(ans, cost_init + cost3(cnt) + 1);
				cnt[1] += 2;
			}
		}
		if(N%3 == 1) {
			if(N >= 4) {
				max_days = 4;
				for(int i = 0; i < (N-4)/3; i++) max_days = max_days * 3 % mod;
			}
			for(int k = 2; k <= 4; k++) if(cnt[k]) {
				cnt[k]--;
				cnt[k-2]++;
				for(int a = 2; a <= 4; a++) if(cnt[a]) {
					cnt[a]--;
					cnt[a-2]++;
					ans = min(ans, cost_init + cost3(cnt) + (k != 2) + (a != 2));
					cnt[a]++;
					cnt[a-2]--;
				}
				if(cnt[1] >= 2) {
					cnt[1] -= 2;
					ans = min(ans, cost_init + cost3(cnt) + (k != 2) + 1);
					cnt[1] += 2;
				}
				cnt[k]++;
				cnt[k-2]--;
			}
			if(cnt[1] >= 2) {
				cnt[1] -= 2;
				for(int a = 2; a <= 4; a++) if(cnt[a]) {
					cnt[a]--;
					cnt[a-2]++;
					ans = min(ans, cost_init + cost3(cnt) + 1 + (a != 2));
					cnt[a]++;
					cnt[a-2]--;
				}
				if(cnt[1] >= 2) {
					cnt[1] -= 2;
					ans = min(ans, cost_init + cost3(cnt) + 2);
					cnt[1] += 2;
				}
				cnt[1] += 2;
			}
			if(cnt[4]) {
				cnt[4]--;
				ans = min(ans, cost_init + cost3(cnt));
				cnt[4]++;
			}
			if(cnt[3] && cnt[1]) {
				cnt[3]--;
				cnt[1]--;
				ans = min(ans, cost_init + cost3(cnt) + 1);
				cnt[3]++;
				cnt[1]++;
			}
		}
		cout << max_days << " " << ans << "\n";
	}
}

// look at my code
// my code is amazing
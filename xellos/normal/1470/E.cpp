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
	int T;
	cin >> T;
	while(T--) {
		int N, C, Q;
		cin >> N >> C >> Q;
		vector<cat> cnt[5];
		cnt[0].resize(N+1, 1);
		cat MX = 1000000000000000010LL;
		for(int k = 1; k < 5; k++) {
			cnt[k].resize(N+1, 0);
			for(int i = N-1; i >= 0; i--)
				for(int j = i; j <= min(i+k, N-1); j++)
					cnt[k][i] = min(MX, cnt[k][i] + cnt[k-(j-i)][j+1]);
		}
		for(int k = 0; k < 4; k++)
			for(int i = 0; i <= N; i++)
				cnt[k+1][i] = min(MX, cnt[k+1][i] + cnt[k][i]);
		vector<int> P(N);
		for(int i = 0; i < N; i++) cin >> P[i];
		vector<cat> sum_lt[5];
		for(int k = 0; k < 5; k++) {
			sum_lt[k].resize(N+1, 0);
			for(int i = 0; i < N; i++)
				for(int j = i; j <= min(i+k, N-1); j++) if(P[j] < P[i])
					sum_lt[k][i] = min(MX, sum_lt[k][i] + cnt[k-(j-i)][j+1]);
			for(int i = N-1; i >= 0; i--) sum_lt[k][i] = min(MX, sum_lt[k][i] + sum_lt[k][i+1]);
		}
		vector<cat> mi[5][17];
		for(int k = 0; k < 5; k++) for(int j = 0; j < 17; j++) {
			mi[k][j].resize(N+1, MX);
			if(j == 0)
				for(int i = 0; i <= N; i++) mi[k][j][i] = cnt[k][i]-sum_lt[k][i];
			else
				for(int i = 0; i <= N; i++) mi[k][j][i] = min(mi[k][j-1][i], mi[k][j-1][min(N, i+(1<<(j-1)))]);
		}
		for(int q = 0; q < Q; q++) {
			int id;
			cat p_id;
			cin >> id >> p_id;
			if(p_id > cnt[C][0]) {
				cout << "-1\n";
				continue;
			}
			int c = C;
			for(int i = 0; i < id; i++) {
				int l = i, r = id+1;
				cat x = p_id-sum_lt[c][i];
				while(r-l > 1) {
					int m = (l+r)/2;
					if(sum_lt[c][m] > -x) l = m;
					else r = m;
				}
				int m = i;
				for(int k = 16; k >= 0; k--) if(m+(1<<k) <= l && mi[c][k][m+1] >= x) m += 1<<k;
				if(id-1 < m) {
					cout << P[id-1] << "\n";
					break;
				}
				p_id -= sum_lt[c][i]-sum_lt[c][m];
				i = m;
				vector< pair<int, cat> > v;
				for(int j = i; j <= min(i+c, N-1); j++) v.push_back({P[j], cnt[c-(j-i)][j+1]});
				sort(begin(v), end(v));
				int cur = 0;
				while(v[cur].ss < p_id) {
					p_id -= v[cur].ss;
					cur++;
				}
				int d = 0;
				while(P[i+d] != v[cur].ff) d++;
				if(id-1 <= i+d) {
					cout << P[i+d-(id-1-i)] << "\n";
					break;
				}
				i += d;
				c -= d;
			}
		}
	}
}

// look at my code
// my code is amazing
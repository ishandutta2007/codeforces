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
	fin() = default;

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
		int N, M;
		cin >> N >> M;
		vector< vector<int> > G(N+2);
		for(int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 1; i <= N; i++) {
			G[0].push_back(i);
			G[i].push_back(0);
			G[N+1].push_back(i);
			G[i].push_back(N+1);
		}
		vector<char> A(N+1, 0);
		for(int i = 0; i < N+1; i++) for(auto x : G[i]) if(x == i+1) A[i] = 1;
		int bl = 0;
		while(bl < N+1 && A[bl]) bl++;
		if(bl == N+1) {
			cout << 1LL*N*(N-1)/2 << "\n";
			continue;
		}
		int br = N;
		while(A[br]) br--;
		bool ok_mid[2] = {0, 0};
		vector<char> dp_mid(N+2, 0);
		dp_mid[bl] = 1;
		for(int i = bl, bm = bl+1; i < br; i++) {
			if(A[i] == 0) {
				bm = i+1;
				while(A[bm]) bm++;
			}
			for(auto v : G[i]) if(v >= i+2 && v <= bm+1)
				dp_mid[v-1] |= (dp_mid[i]>>1) | ((dp_mid[i]&1)<<1);
		}
		if(dp_mid[br] == 0) {
			cout << "0\n";
			continue;
		}
		ok_mid[0] = dp_mid[br]&1, ok_mid[1] = dp_mid[br]>>1;
		vector<char> dp_l(N+2, 0);
		dp_l[bl] = 1;
		for(int i = bl; i > 0; i--) {
			for(auto v : G[i+1]) if(v <= i-1)
				dp_l[v] |= (dp_l[i]>>1) | ((dp_l[i]&1)<<1);
		}
		vector<char> dp_r(N+2, 0);
		dp_r[br] = 1;
		for(int i = br; i < N+2; i++) {
			for(auto v : G[i]) if(v >= i+2)
				dp_r[v-1] |= (dp_r[i]>>1) | ((dp_r[i]&1)<<1);
		}
		cat ans = 0;
		if(ok_mid[0] && ok_mid[1]) {
			cat cnt_l = 0, cnt_r = 0;
			for(int i = 0; i < N+2; i++) {
				if(dp_l[i]) cnt_l++;
				if(dp_r[i]) cnt_r++;
			}
			ans = cnt_l * cnt_r;
		}
		else {
			if(ok_mid[1])
				for(int i = br; i < N+2; i++)
					dp_r[i] = (dp_r[i]>>1) | ((dp_r[i]&1)<<1);
			cat cnt[2][4];
			memset(cnt, 0, sizeof(cnt));
			for(int i = 0; i <= bl; i++) cnt[0][dp_l[i]]++;
			for(int i = br; i < N+2; i++) cnt[1][dp_r[i]]++;
			for(int i = 1; i < 4; i++) for(int j = 1; j < 4; j++) if(i&j)
				ans += cnt[0][i] * cnt[1][j];
		}
		if(bl == br) ans--;
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing
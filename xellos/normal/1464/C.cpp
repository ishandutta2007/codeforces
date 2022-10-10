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
	int N;
	cat V;
	string S;
	cin >> N >> V >> S;
	V -= 1LL<<(S[N-1]-'a');
	V += 1LL<<(S[N-2]-'a');
	vector<int> cnt(50, 0);
	for(int i = 0; i < N-2; i++) cnt[S[i]-'a']++;
	for(int i = 0; i < 49; i++) while(cnt[i] >= 3) {
		cnt[i] -= 2;
		cnt[i+1]++;
	}
	cat Vmin = V, Vmax = V;
	for(int i = 0; i < 50; i++) {
		// V in [Vmin, Vmax] step 2^i
		vector<cat> cand_min;
		for(int k = 0; k < 1 + (Vmin != Vmax); k++) for(int a = 0; a <= cnt[i]; a++)
			cand_min.push_back(Vmin+k*(1LL<<i)+a*(1LL<<i)-(cnt[i]-a)*(1LL<<i));
		cat Vmin_new = Vmax + (2LL<<i);
		for(auto v : cand_min) if(abs(v)%(1LL<<(i+1)) == 0) Vmin_new = min(Vmin_new, v);
		if(Vmin_new == Vmax+(2LL<<i)) {
			cout << "No\n";
			return 0;
		}
		vector<cat> cand_max;
		for(int k = 0; k < 1 + (Vmin != Vmax); k++) for(int a = 0; a <= cnt[i]; a++)
			cand_max.push_back(Vmax-k*(1LL<<i)+a*(1LL<<i)-(cnt[i]-a)*(1LL<<i));
		cat Vmax_new = Vmin - (2LL<<i);
		for(auto v : cand_max) if(abs(v)%(1LL<<(i+1)) == 0) Vmax_new = max(Vmax_new, v);
		if(Vmax_new == Vmin-(2LL<<i)) {
			cout << "No\n";
			return 0;
		}
		Vmin = Vmin_new, Vmax = Vmax_new;
	}
	if(Vmin <= 0 && Vmax >= 0) cout << "Yes\n";
	else cout << "No\n";
}

// look at my code
// my code is amazing
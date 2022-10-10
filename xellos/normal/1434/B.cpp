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
#define OVER9000 1234567890123LL
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<char> t(2*N, 0);
	vector<int> pos(N), val(2*N);
	for(int i = 0; i < 2*N; i++) {
		static string s;
		cin >> s;
		if(s == "+") continue;
		t[i] = 1;
		cin >> val[i];
		pos[--val[i]] = i;
	}
	set<int> free_add, free_rm;
	for(int i = 0; i < 2*N; i++) {
		if(t[i]) free_rm.insert(i);
		else free_add.insert(i);
	}
	vector<int> ans(2*N);
	for(int i = 0; i < N; i++) {
		int r = pos[i];
		auto it = free_add.lower_bound(r);
		if(it == begin(free_add)) {
			cout << "NO\n";
			return 0;
		}
		it--;
		int l = *it;
		auto jt = free_rm.lower_bound(l);
		if(*jt != r) {
			cout << "NO\n";
			return 0;
		}
		ans[l] = i;
		free_rm.erase(jt);
		free_add.erase(it);
	}
	cout << "YES\n";
	for(int i = 0; i < 2*N; i++) if(t[i] == 0) cout << ans[i]+1 << " ";
	cout << "\n";
}

// look at my code
// my code is amazing
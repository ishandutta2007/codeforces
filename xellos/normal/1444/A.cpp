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
	int T;
	cin >> T;
	while(T--) {
		cat P, Q;
		cin >> P >> Q;
		cat tmp = Q;
		static vector<cat> pr;
		pr.clear();
		for(cat r = 2; r*r <= tmp; r++) if(tmp%r == 0) {
			while(tmp%r == 0) tmp /= r;
			pr.push_back(r);
		}
		if(tmp > 1) pr.push_back(tmp);
		cat ans = 1;
		for(auto p : pr) {
			int eP = 0, eQ = 0;
			tmp = Q;
			while(tmp%p == 0) tmp /= p, eQ++;
			tmp = P;
			while(tmp%p == 0) tmp /= p, eP++;
			if(eP >= eQ) {
				for(int i = 0; i < eQ-1; i++) tmp *= p;
				ans = max(ans, tmp);
			}
			else ans = P;
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing
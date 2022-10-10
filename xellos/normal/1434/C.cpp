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
		cat A, B, C, D;
		cin >> A >> B >> C >> D;
		if(A > B*C) {
			cout << "-1\n";
			continue;
		}
		if(D >= C) {
			cout << A << "\n";
			continue;
		}
		cat ans = A;
		cat X = 1;
		for(int k = 20; k >= 0; k--) while(true) {
			X += 1<<k;
			cat der = 2*A - (2*X-1) * B*D;
			if(der < 0) {
				X -= 1<<k;
				break;
			}
			ans = X * A - X*(X-1)/2 * B*D;
		}
		ans = max(ans, (X+1) * A - X*(X+1)/2 * B*D);
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing
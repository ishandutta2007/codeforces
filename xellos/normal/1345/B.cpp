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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	set<int> sz;
	for(int i = 2, h = 1; i <= OVER9000; h++) {
		sz.insert(i);
		i += 3*h+2;
	}
	while(T--) {
		int N, ans = 0;
		cin >> N;
		while(true) {
			auto it = sz.upper_bound(N);
			if(it == begin(sz)) break;
			it--;
			N -= *it;
			ans++;
		}
		cout << ans << "\n";
	}	
	return 0;
}

// look at my code
// my code is amazing
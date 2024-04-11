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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<int, int> > A(N, {0, 0});
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < (int)s.length(); j++) {
			if(s[j] == 'B') A[i].ff++;
			else A[i].ss++;
		}
	}
	int min_ans = -1, max_ans = 10000000;
	pair<int, int> ans_p = {0, 0};
	while(max_ans-min_ans > 1) {
		int cur = (min_ans + max_ans) / 2;
		int min_x = 0, min_y = 0, max_x = 10000000, max_y = 10000000;
		for(int i = 0; i < N; i++) {
			min_x = max(min_x, A[i].ff - cur);
			max_x = min(max_x, A[i].ff + cur);
			min_y = max(min_y, A[i].ss - cur);
			max_y = min(max_y, A[i].ss + cur);
		}
		int min_dif = -10000000, max_dif = 10000000;
		for(int i = 0; i < N; i++) {
			min_dif = max(min_dif, A[i].ff-A[i].ss - cur);
			max_dif = min(max_dif, A[i].ff-A[i].ss + cur);
		}
		bool ok = (min_x <= max_x && min_y <= max_y && min_dif <= max_dif);
		if(min_x-max_y > max_dif || max_x-min_y < min_dif) ok = false;
		if(ok) {
			ans_p = {min_x, max_y};
			if(ans_p.ff-ans_p.ss < min_dif) {
				int d = min(max_x-ans_p.ff, min_dif-(ans_p.ff-ans_p.ss));
				ans_p.ff += d;
			}
			if(ans_p.ff-ans_p.ss < min_dif) {
				int d = min(ans_p.ss-min_y, min_dif-(ans_p.ff-ans_p.ss));
				ans_p.ss -= d;
			}
			max_ans = cur;
		}
		else min_ans = cur;
	}
	cout << max_ans << "\n";
	string ans_s;
	for(int i = 0; i < ans_p.ff; i++) ans_s += 'B';
	for(int i = 0; i < ans_p.ss; i++) ans_s += 'N';
	cout << ans_s << "\n";
}

// look at my code
// my code is amazing
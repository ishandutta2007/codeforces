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
	while(T--) {
		int N;
		cin >> N;
		vector<int> P(N), pos(N);
		map<int, int> cnt_pos;
		multiset<int> cnt_q;
		for(int i = 0; i < N; i++) {
			cin >> P[i];
			pos[--P[i]] = i;
			cnt_pos[i] = 0;
			cnt_q.insert(0);
		}
		bool ok = true;
		for(int i = 0; i < N; i++) {
			int c = cnt_pos[pos[i]];
			if(*rbegin(cnt_q) != c) {
				ok = false;
				break;
			}
			cnt_q.erase(--end(cnt_q));
			auto it = cnt_pos.upper_bound(pos[i]);
			if(it != end(cnt_pos)) {
				cnt_q.erase(cnt_q.find(it->ss));
				it->ss += c+1;
				cnt_q.insert(it->ss);
			}
			it--;
			cnt_pos.erase(it);
		}
		cout << (ok ? "Yes\n" : "No\n");
	}
	return 0;
}

// look at my code
// my code is amazing
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

void flip(char & c) {
	if(c == '1') c = '0';
	else c = '1';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<string> S(N);
		for(int i = 0; i < N; i++) cin >> S[i];
		vector< pair<int, int> > ans;
		for(int i = N-1; i >= 2; i--) {
			for(int j = 0; j < M-1; j++) if(S[i][j] == '1') {
				ans.push_back({i, j});
				ans.push_back({i, j+1});
				ans.push_back({i-1, j});
				flip(S[i][j+1]);
				flip(S[i-1][j]);
			}
			if(S[i][M-1] == '1') {
				ans.push_back({i, M-1});
				ans.push_back({i-1, M-1});
				ans.push_back({i-1, M-2});
				flip(S[i-1][M-1]);
				flip(S[i-1][M-2]);
			}
		}
		for(int i = M-1; i >= 2; i--) {
			if(S[0][i] == '1') {
				ans.push_back({0, i});
				ans.push_back({0, i-1});
				ans.push_back({1, i-1});
				flip(S[0][i-1]);
				flip(S[1][i-1]);
			}
			if(S[1][i] == '1') {
				ans.push_back({1, i});
				ans.push_back({0, i-1});
				ans.push_back({1, i-1});
				flip(S[0][i-1]);
				flip(S[1][i-1]);
			}
		}
		for(int b = 0; b < (1<<4); b++) {
			int st = (S[0][0] == '1') + 2 * (S[0][1] == '1') + 4 * (S[1][0] == '1') + 8 * (S[1][1] == '1');
			if(b&1) st ^= (2+4+8);
			if(b&2) st ^= (1+4+8);
			if(b&4) st ^= (1+2+8);
			if(b&8) st ^= (1+2+4);
			if(st) continue;
			if(b&1) {
				ans.push_back({0, 1});
				ans.push_back({1, 1});
				ans.push_back({1, 0});
			}
			if(b&2) {
				ans.push_back({0, 0});
				ans.push_back({1, 1});
				ans.push_back({1, 0});
			}
			if(b&4) {
				ans.push_back({0, 0});
				ans.push_back({1, 1});
				ans.push_back({0, 1});
			}
			if(b&8) {
				ans.push_back({0, 1});
				ans.push_back({0, 0});
				ans.push_back({1, 0});
			}
			break;
		}
		cout << ans.size()/3 << "\n";
		for(int i = 0; i < (int)ans.size()/3; i++)
			cout << ans[3*i].ff+1 << " " << ans[3*i].ss+1 << " " << ans[3*i+1].ff+1 << " " << ans[3*i+1].ss+1 << " " << ans[3*i+2].ff+1 << " " << ans[3*i+2].ss+1 << "\n";
	}
}

// look at my code
// my code is amazing
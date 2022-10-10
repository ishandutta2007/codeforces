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
	int N, M, K;
	cin >> N >> M >> K;
	vector< vector< pair<int, int> > > E_out(N);
	for(int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E_out[u-1].push_back({w, v-1});
	}
	vector< vector< pair<int, int> > > E_in(N);
	for(int i = 0; i < N; i++) {
		sort(begin(E_out[i]), end(E_out[i]));
		for(int j = 0; j < (int)E_out[i].size(); j++)
			E_in[E_out[i][j].ss].push_back({E_out[i].size(), j});
	}
	char bl[10][10];
	memset(bl, 0, sizeof(bl));
	char bl_p[10][10][10][10];
	memset(bl_p, 0, sizeof(bl_p));
	int cnt[10][10];
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < N; i++) {
		char occ[10][10];
		memset(occ, 0, sizeof(occ));
		for(auto p : E_in[i]) occ[p.ff][p.ss]++;
		for(int j = 1; j <= K; j++) for(int k = 0; k < j; k++) {
			if(occ[j][k] > 1) bl[j][k] = 1;
			if(occ[j][k] == 1) {
				cnt[j][k]++;
				for(int l = j+1; l <= K; l++) for(int m = 0; m < l; m++)
					if(occ[l][m] == 1) bl_p[j][k][l][m] = 1;
			}
		}
	}
	int P_cnt = 1;
	for(int i = 1; i <= K; i++) P_cnt *= i;
	int ans = 0;
	for(int i = 0; i < P_cnt; i++) {
		int st[10];
		for(int j = 0, a = i; j < K; j++) {
			st[j] = a%(j+1);
			a /= j+1;
		}
		int sum_cnt = 0;
		bool ok = true;
		char is_bl[10][10];
		memset(is_bl, 0, sizeof(is_bl));
		for(int j = 0; j < K; j++) {
			if(bl[j+1][st[j]] || is_bl[j+1][st[j]]) {
				ok = false;
				break;
			}
			for(int k = j+1; k < K; k++) for(int l = 0; l <= k; l++)
				is_bl[k+1][l] |= bl_p[j+1][st[j]][k+1][l];
			sum_cnt += cnt[j+1][st[j]];
		}
		if(ok && sum_cnt == N) ans++;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing
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
	string S, T;
	cin >> S >> T;
	int N = S.length(), M = T.length();
	cat mod = 998244353, ans = 0;
	vector< vector<cat> > cnt_pref(N+1, vector<cat>(M+1, 0));
	vector<cat> pw2(N+1, 1);
	for(int i = 1; i <= N; i++) pw2[i] = pw2[i-1] * 2 % mod;
	cnt_pref[N][0] = 1;
	cat last = 0;
	for(int i = N-1; i >= 0; i--) {
		cnt_pref[i][0] = N-i+1;
		for(int j = M; j >= 1; j--) cnt_pref[i][j] = cnt_pref[i+1][j];
		for(int j = M-1; j >= 0; j--) if(S[i] == T[j]) {
			cnt_pref[i][j+1] += cnt_pref[i+1][j];
			if(cnt_pref[i][j+1] >= mod) cnt_pref[i][j+1] -= mod;
		}
		ans += pw2[i] * (cnt_pref[i][M]+mod-last) % mod;
		last = cnt_pref[i][M];
	}
	if(T[M-1] == S[0]) ans += cnt_pref[1][M-1];
	vector<cat> cnt_sub(M, 0);
	for(int i = 0; i < M; i++) if(T[i] == S[0]) cnt_sub[i] = 2;
	for(int i = 1; i < M; i++) {
		vector<cat> cnt_sub_nw(M-i, 0);
		for(int j = 0; j < M-i; j++) if(T[j] == S[i]) cnt_sub_nw[j] = cnt_sub[j+1];
		for(int j = 0; j < M-i; j++) if(T[j+i] == S[i]) {
			cnt_sub_nw[j] += cnt_sub[j];
			if(cnt_sub_nw[j] >= mod) cnt_sub_nw[j] -= mod;
			if(j == M-i-1) ans += cnt_pref[i+1][M-i-1] * cnt_sub[M-i-1] % mod;
		}
		cnt_sub = cnt_sub_nw;
	}
	ans %= mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
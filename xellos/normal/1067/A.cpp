#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, MX = 200;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	cat mod = 998244353;
	vector< vector< vector<cat> > > cnt(N+1, vector< vector<cat> >(2, vector<cat>(MX+1, 0)));
	cnt[0][1][0] = 1;
	for(int i = 0; i < N; i++) {
		cat s = 0;
		for(int j = 1; j <= MX; j++) {
			s += cnt[i][0][j-1];
			if(s >= mod) s -= mod;
			s += cnt[i][1][j-1];
			if(s >= mod) s -= mod;
			if(A[i] == -1 || A[i] == j) cnt[i+1][0][j] = s;
		}
		s = 0;
		for(int j = MX; j >= 1; j--) {
			s += cnt[i][1][j];
			if(s >= mod) s -= mod;
			if(A[i] == -1 || A[i] == j) {
				cnt[i+1][1][j] = s + cnt[i][0][j];
				if(cnt[i+1][1][j] >= mod) cnt[i+1][1][j] -= mod;
			}
		}
	}
	cat ans = 0;
	for(int i = 1; i <= MX; i++) ans = (ans + cnt[N][1][i]) % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
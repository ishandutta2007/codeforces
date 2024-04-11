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
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> cnt_A(N+1, 0), cnt_B(M+1, 0);
	for(int i = 0, cur = 0, a; i < N; i++) {
		cin >> a;
		cur = (cur+a)*a;
		cnt_A[cur]++;
	}
	for(int i = N; i > 0; i--) cnt_A[i-1] += cnt_A[i];
	for(int i = 0, cur = 0, a; i < M; i++) {
		cin >> a;
		cur = (cur+a)*a;
		cnt_B[cur]++;
	}
	for(int i = M; i > 0; i--) cnt_B[i-1] += cnt_B[i];
	cat ans = 0;
	for(int i = 1; i <= min(N, K); i++) if(K%i == 0)
		if(K/i <= M) ans += 1LL * cnt_A[i] * cnt_B[K/i];
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
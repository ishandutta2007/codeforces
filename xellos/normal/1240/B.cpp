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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			A[i]--;
		}
		vector<int> n_ge(N+1, 0), n_le(N, 0);
		for(int i = 0; i < N; i++) n_ge[A[i]] = n_le[A[i]] = 1;
		for(int i = 1; i < N; i++) n_le[i] += n_le[i-1];
		for(int i = N-2; i >= 0; i--) n_ge[i] += n_ge[i+1];
		vector< pair<int, int> > I(N, {N, -1});
		for(int i = 0; i < N; i++) I[A[i]].ff = min(I[A[i]].ff, i);
		for(int i = 0; i < N; i++) I[A[i]].ss = max(I[A[i]].ss, i);
		vector<int> prev(N+1, -1);
		for(int i = 0; i < N; i++) prev[A[i]+1] = A[i];
		for(int i = 1; i <= N; i++) if(prev[i] == -1) prev[i] = prev[i-1];
		int ans = N;
		for(int i = 0; i < N; i++) if(I[A[i]].ss == i) {
			int cur = A[i];
			while(prev[cur] != -1 && I[prev[cur]].ss < I[cur].ff) cur = prev[cur];
			ans = min(ans, n_ge[A[i]+1] + (cur ? n_le[cur-1] : 0));
		}
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
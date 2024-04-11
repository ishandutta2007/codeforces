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
	int N, S, M, K;
	cin >> N >> S >> M >> K;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> As = A;
	sort(begin(As), end(As));
	int n = 0;
	{
		auto it = unique(begin(As), end(As));
		n = it - begin(As);
	}
	vector<int> L(S), R(S);
	for(int i = 0; i < S; i++) cin >> L[i] >> R[i];
	vector<bool> live(S, true);
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) if(i != j) {
			if(L[j] == L[i] && R[j] == R[i] && i < j) continue;
			if(L[j] <= L[i] && R[j] >= R[i]) live[i] = false;
		}
	}
	vector< pair<int, int> > I;
	for(int i = 0; i < S; i++) if(live[i]) I.push_back({L[i], R[i]});
	sort(begin(I), end(I));
	S = I.size();
	for(int i = 0; i < S; i++) L[i] = I[i].ff, R[i] = I[i].ss;
	vector<int> nxt(S, S);
	for(int i = 0; i < S; i++) for(int j = i+1; j < S; j++) if(L[j] > R[i]) {
		nxt[i] = j;
		break;
	}
	int l = -1, r = n;
	vector< vector<int> > dp_used(S+1, vector<int>(M+1, -N));
	vector< vector<int> > dp_free(S+1, vector<int>(M+1, -N));
	while(r-l > 1) {
		int c = (l + r) / 2;
		vector<int> sum(N+1, 0);
		for(int i = 0; i < N; i++) sum[i+1] = sum[i] + (A[i] <= As[c]);
		for(int i = 0; i < S; i++) for(int j = 0; j <= M; j++) dp_used[i][j] = dp_free[i][j] = -N;
		for(int i = 0; i < S; i++) dp_free[i][0] = 0, dp_used[i][1] = sum[R[i]]-sum[L[i]-1];
		for(int i = 0; i < S-1; i++) for(int j = 0; j <= min(i+1, M); j++) {
			// segment i free, take i+1?
			dp_free[i+1][j] = max(dp_free[i+1][j], dp_free[i][j]);
			if(j < M) dp_used[i+1][j+1] = max(dp_used[i+1][j+1], dp_free[i][j] + sum[R[i+1]]-sum[L[i+1]-1]);
			// segment i used, take nxt[i]?
			if(nxt[i] < S) {
				dp_free[nxt[i]][j] = max(dp_free[nxt[i]][j], dp_used[i][j]);
				if(j < M) dp_used[nxt[i]][j+1] = max(dp_used[nxt[i]][j+1], dp_used[i][j] + sum[R[nxt[i]]]-sum[L[nxt[i]]-1]);
			}
			// segmeny i used, take nxt[i]-1?
			if(nxt[i] > i+1 && j < M) {
				dp_used[nxt[i]-1][j+1] = max(dp_used[nxt[i]-1][j+1], dp_used[i][j] + sum[R[nxt[i]-1]]-sum[R[i]]);
			}
		}
		bool ok = false;
		for(int i = 0; i < S; i++) for(int j = 0; j <= M; j++) if(dp_used[i][j] >= K) ok = true;
		if(ok) r = c;
		else l = c;
	}
	if(r == n) cout << "-1\n";
	else cout << As[r] << "\n";
	return 0;
}

// look at my code
// my code is amazing
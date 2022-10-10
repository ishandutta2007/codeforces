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
	int N, P;
	cin >> N >> P;
	vector<int> L(N), ids(N);
	vector< pair<int, int> > I(N);
	for(int i = 0; i < N; i++) {
		cin >> I[i].ff >> I[i].ss >> L[i];
		I[i].ss += I[i].ff-1;
		ids[i] = i;
	}
	for(int i = 0; i < N; i++) for(int j = i+1; j < N; j++) if(I[j].ff < I[i].ff) {
		swap(I[j], I[i]);
		swap(ids[j], ids[i]);
	}
	vector< pair<int, int> > match_pair;
	uint8_t match_id[50][50];
	for(int k = 0; k <= N; k++) for(int i = 0; i <= k; i++) {
		match_id[i][k] = (uint8_t) min(255, (int)match_pair.size());
		match_pair.push_back({i, k});
	}
	vector< vector<int> > dp(N+1, vector<int>(1<<N, 0));
	vector< vector<uint8_t> > prev(N+1, vector<uint8_t>(1<<N));
	dp[0][0] = 1;
	bool ans_found = false;
	vector<int> next_free_spot(N), last_visa_stime(N);
	for(int i = 0; i < N; i++) {
		last_visa_stime[i] = I[i].ff-L[ids[i]];
		next_free_spot[i] = I[i].ss+1;
		for(int j = i+1; j < N; j++) if(next_free_spot[i] == I[j].ff) next_free_spot[i] = I[j].ss+1;
	}
	vector<bool> exists(1<<N, false);
	for(int i = 0; i < N; i++) for(int j = 0; j < (1<<N); j++) if(dp[i][j] != 0) {
		if(i > 0) dp[i][j] = max(dp[i][j], I[i-1].ss+1);
		if(dp[i][j] >= I[i].ff) dp[i][j] = max(dp[i][j], next_free_spot[i]);
		if(dp[i+1][j] == 0 || dp[i+1][j] > dp[i][j]) {
			dp[i+1][j] = dp[i][j];
			prev[i+1][j] = match_id[i][N];
		}
		if(P == 1 && j == (1<<N)-1) ans_found = true;
		if(P == 2 && exists[(1<<N)-1-j] != 0) ans_found = true;
		if(ans_found) continue;
		exists[j] = true;
		int next_one = i;
		while(next_one < N && ((j>>next_one)&1) == 0) next_one++;
		for(int k = i; k < N; k++) if(((j>>k)&1) == 0 && !exists[j+(1<<k)] && dp[i][j] < last_visa_stime[k]) {
			if(dp[i][j]+L[ids[k]] < I[i].ff) {
				if(dp[i][j+(1<<k)] == 0 || dp[i][j+(1<<k)] > dp[i][j]+L[ids[k]]) {
					dp[i][j+(1<<k)] = dp[i][j]+L[ids[k]];
					prev[i][j+(1<<k)] = match_id[i][k];
				}
			}
			else {
				int nxt = i, t = dp[i][j]+L[ids[k]];
				int this_next_one = min(k, next_one);
				bool ok = (t < I[this_next_one].ff);
				if(ok) {
					while(nxt < N && t >= I[nxt].ff) nxt++;
					t = max(t, I[nxt-1].ss);
				}
				if(ok && (dp[nxt][j+(1<<k)] == 0 || dp[nxt][j+(1<<k)] > t)) {
					dp[nxt][j+(1<<k)] = t;
					prev[nxt][j+(1<<k)] = match_id[i][k];
				}
			}
		}
	}
	if(P == 1) {
		if(dp[N][(1<<N)-1] == 0) {
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		pair<int, int> cur = {N, (1<<N)-1};
		vector<int> ans_day(N);
		while(cur.ss > 0) {
			pair<int, int> p = match_pair[prev[cur.ff][cur.ss]];
			if(p.ss == N) {
				cur.ff--;
				continue;
			}
			ans_day[ids[p.ss]] = dp[p.ff][cur.ss-(1<<p.ss)];
			cur.ff = p.ff;
			cur.ss -= 1<<p.ss;
		}
		for(int i = 0; i < N; i++) cout << "1 " << ans_day[i] << "\n";
		return 0;
	}
	for(int i = 0; i < (1<<N); i++) if(dp[N][i] != 0 && dp[N][(1<<N)-1-i] != 0) {
		cout << "YES\n";
		vector<int> ans_type(N), ans_day(N);
		for(int k = 0; k < 2; k++) {
			pair<int, int> cur = {N, (k == 0) ? i : ((1<<N)-1-i)};
			while(cur.ss > 0) {
				pair<int, int> p = match_pair[prev[cur.ff][cur.ss]];
				if(p.ss == N) {
					cur.ff--;
					continue;
				}
				ans_day[ids[p.ss]] = dp[p.ff][cur.ss-(1<<p.ss)];
				ans_type[ids[p.ss]] = k;
				cur.ff = p.ff;
				cur.ss -= 1<<p.ss;
			}
		}
		for(int i = 0; i < N; i++) cout << ans_type[i]+1 << " " << ans_day[i] << "\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}

// look at my code
// my code is amazing
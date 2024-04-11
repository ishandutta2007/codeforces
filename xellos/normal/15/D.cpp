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

struct city {
	cat cost;
	int r, c;

	bool operator<(const city & C) const {
		if(cost != C.cost) return cost < C.cost;
		if(r != C.r) return r < C.r;
		return c < C.c;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, A, B;
	cin >> N >> M >> A >> B;
	vector< vector<cat> > H(N, vector<cat>(M));
	for(int i = 0; i < N*M; i++) cin >> H[i/M][i%M];
	vector< vector<cat> > pref_sum(N+1, vector<cat>(M+1, 0));
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
		pref_sum[i+1][j+1] = pref_sum[i][j+1]+pref_sum[i+1][j]-pref_sum[i][j]+H[i][j];
	vector< vector<cat> > sum(N-A+1, vector<cat>(M-B+1, 0));
	for(int i = 0; i <= N-A; i++) for(int j = 0; j <= M-B; j++)
		sum[i][j] = pref_sum[i+A][j+B]-pref_sum[i+A][j]-pref_sum[i][j+B]+pref_sum[i][j];
	vector< vector<cat> > min_up(N-A+1, vector<cat>(M));
	for(int j = 0; j < M; j++) {
		deque<int> q;
		for(int i = 0; i < N; i++) {
			while(!q.empty() && H[q.front()][j] >= H[i][j]) q.pop_front();
			q.push_front(i);
			while(q.back() <= i-A) q.pop_back();
			if(i >= A-1) min_up[i-A+1][j] = H[q.back()][j];
		}
	}
	vector< vector<cat> > min_v(N-A+1, vector<cat>(M-B+1));
	for(int i = 0; i <= N-A; i++) {
		deque<int> q;
		for(int j = 0; j < M; j++) {
			while(!q.empty() && min_up[i][q.front()] >= min_up[i][j]) q.pop_front();
			q.push_front(j);
			while(q.back() <= j-B) q.pop_back();
			if(j >= B-1) min_v[i][j-B+1] = min_up[i][q.back()];
		}
	}
	vector<city> C((N-A+1)*(M-B+1));
	for(int i = 0; i <= N-A; i++) for(int j = 0; j <= M-B; j++)
		C[i*(M-B+1)+j] = {sum[i][j] - min_v[i][j] * A * B, i, j};
	sort(begin(C), end(C));
	vector< vector<char> > full(N-A+1, vector<char>(M-B+1, 0));
	vector<city> ans;
	for(int i = 0; i < (N-A+1)*(M-B+1); i++) if(!full[C[i].r][C[i].c]) {
		for(int r = max(0, C[i].r-A+1); r < min(N-A+1, C[i].r+A); r++)
			for(int c = max(0, C[i].c-B+1); c < min(M-B+1, C[i].c+B); c++)
				full[r][c] = 1;
		ans.push_back(C[i]);
	}
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x.r+1 << " " << x.c+1 << " " << x.cost << "\n";
	return 0;
}

// look at my code
// my code is amazing
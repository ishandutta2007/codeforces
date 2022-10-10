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

struct condition {
	int l, r, h, cost;
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, H, M;
	cin >> N >> H >> M;
	vector<condition> C(M);
	for(int i = 0; i < M; i++) {
		cin >> C[i].l >> C[i].r >> C[i].h >> C[i].cost;
		C[i].l--, C[i].r--;
	}
	vector< vector< vector<int> > > c_sum(N, vector< vector<int> >(N, vector<int>(N, 0)));
	vector< vector<int> > ans(N, vector<int>(N, 0));
	for(int h = 1; h <= H; h++) {
		for(int j = 0; j < M; j++) if(C[j].h == h-1)
			for(int l = 0; l <= C[j].l; l++) for(int r = C[j].r; r < N; r++)
				for(int i = C[j].l; i <= C[j].r; i++)
					c_sum[l][r][i] += C[j].cost;
		for(int d = 1; d <= N; d++) for(int l = 0; l <= N-d; l++) for(int i = l; i < l+d; i++) {
			int ans_l = (i == l) ? 0 : ans[l][i-1];
			int ans_r = (i == l+d-1) ? 0 : ans[i+1][l+d-1];
			ans[l][l+d-1] = max(ans[l][l+d-1], ans_l+ans_r + h*h - c_sum[l][l+d-1][i]);
		}
	}
	cout << ans[0][N-1] << "\n";
	return 0;
}

// look at my code
// my code is amazing
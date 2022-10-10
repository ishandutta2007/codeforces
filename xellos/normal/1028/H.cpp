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

struct query {
	int l, r, id;

	bool operator<(const query & Q) const {
		return r < Q.r;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q, MX = 5050000;
	cin >> N >> Q;
	vector<int> div(MX+1, 1);
	for(int i = 2; i <= MX; i++) if(div[i] == 1) {
		div[i] = i;
		for(int j = i; j <= MX/i; j++) div[i*j] = i;
	}
	vector< vector<int> > A(N);
	vector< vector<int> > prod_groups(MX);
	vector<int> prod_sz(MX, 0);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		while(a > 1) {
			int e = 0, p = div[a];
			while(a%p == 0) a /= p, e++;
			if(e&1) A[i].push_back(p);
		}
		int sz = A[i].size();
		for(int j = 0; j < (1<<sz); j++) {
			int prod = 1, n = 0;
			for(int k = 0; k < sz; k++) if((j>>k)&1) prod *= A[i][k], n++;
			prod_groups[prod].push_back(i);
			prod_sz[prod] = n;
		}
	}
	vector< vector<int> > last(N, vector<int>(15, -1));
	int opt[8];
	for(int i = 0; i < MX; i++) if(!prod_groups[i].empty()) {
		int sz = prod_groups[i].size();
		for(int j = 0; j < 8; j++) opt[j] = -1;
		for(int j = 0; j < sz; j++) {
			int cur = prod_groups[i][j];
			for(int k = 0; k < 8; k++) if(opt[k] != -1)
				last[cur][k+A[cur].size()-prod_sz[i]] = max(last[cur][k+A[cur].size()-prod_sz[i]], opt[k]);
			opt[A[cur].size()-prod_sz[i]] = cur;
		}
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < 14; j++) last[i][j+1] = max(last[i][j+1], last[i][j]);
	vector<int> last_RMQ[15][18];
	for(int i = 0; i < 15; i++) {
		for(int k = 0; k < 18; k++) last_RMQ[i][k].resize(N+1, -1);
		for(int j = 0; j < N; j++) last_RMQ[i][0][j] = last[j][i];
		for(int k = 1; k < 18; k++) for(int j = 0; j < N; j++)
			last_RMQ[i][k][j] = max(last_RMQ[i][k-1][j], last_RMQ[i][k-1][min(N, j+(1<<(k-1)))]);
	}
	for(int q = 0; q < Q; q++) {
		int l, r;
		cin >> l >> r;
		l--;
		int ans = 14;
		for(int k = 17; k >= 0; k--) if(l+(1<<k) <= r) {
			r -= (1<<k);
			for(int i = 0; i < ans; i++) if(last_RMQ[i][k][r] >= l) {
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
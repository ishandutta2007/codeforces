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
	int N;
	cin >> N;
	map<int, int> M;
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		M[a]++;
	}
	vector< pair<int, int> > occ;
	for(auto p : M) occ.push_back({p.ss, p.ff});
	sort(begin(occ), end(occ));
	int r = N+1, r_opt = 1, sz_opt = 1;
	int sum = 0, last = occ.size();
	while(--r) {
		while(last && occ[last-1].ff == r) sum += occ[--last].ff;
		if(1LL*r*r <= N-sum+1LL*(occ.size()-last)*r) {
			int sz = N-sum+1LL*(occ.size()-last)*r;
			if(sz-sz%r > sz_opt) sz_opt = sz-sz%r, r_opt = r;
		}
	}
	r = r_opt;
	int c = sz_opt/r;
	cout << r*c << "\n" << r << " " << c << "\n";
	vector< vector<int> > ans(r, vector<int>(c));
	int cur_r = 0, cur_c = 0;
	reverse(begin(occ), end(occ));
	for(auto p : occ) for(int i = 0; i < min(p.ff, r); i++) {
		ans[cur_r][(cur_c+cur_r)%c] = p.ss;
		if(cur_r == r-1 && cur_c == c-1) {
			for(int k = 0; k < r; k++) for(int j = 0; j < c; j++)
				cout << ans[k][j] << ((j == c-1) ? "\n" : " ");
			return 0;
		}
		if(cur_r == r-1) cur_r = 0, cur_c++;
		else cur_r++;
	}
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++)
		cout << ans[i][j] << ((j == c-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
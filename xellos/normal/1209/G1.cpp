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

cat mod = 1000000007;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q, MX = 200010;
	cin >> N >> Q;
	vector<int> A(N);
	vector<int> max_pos(MX, -1), cnt(MX, 0);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		max_pos[A[i]] = max(max_pos[A[i]], i);
		cnt[A[i]]++;
	}
	int l = 0, ans = 0;
	while(l < N) {
		int r = max_pos[A[l]], i = l, max_cnt = cnt[A[l]];
		while(true) {
			if(i > r) break;
			r = max(r, max_pos[A[i]]);
			max_cnt = max(max_cnt, cnt[A[i]]);
			i++;
		}
		ans += r-l+1-max_cnt;
		l = r+1;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
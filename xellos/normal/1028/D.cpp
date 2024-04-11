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
	int N;
	cin >> N;
	vector<int> tp(N), val(N);
	map<int, int> M;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s >> val[i];
		M[val[i]] = 0;
		if(s == "ADD") tp[i] = 1;
		else tp[i] = 0;
	}
	int m = 0;
	ALL_THE(M, it) it->ss = m++;
	for(int i = 0; i < N; i++) val[i] = M[val[i]];

	cat mod = 1000000007;
	vector<cat> cnt(m+1, 0);
	cnt[m] = 1;
	set<int> live, nz;
	live.insert(m);
	nz.insert(m);
	for(int i = 0; i < N; i++) {
		if(tp[i] == 0) {
			live.erase(val[i]);
			auto it = live.upper_bound(val[i]);
			cnt[*it] += cnt[val[i]];
			if(cnt[*it] >= mod) cnt[*it] -= mod;
			ALL_THE(nz, jt) if(*jt != *it) cnt[*jt] = 0;
			nz.clear();
			nz.insert(*it);
		}
		else {
			auto it = live.upper_bound(val[i]);
			cnt[val[i]] = cnt[*it];
			nz.insert(val[i]);
			live.insert(val[i]);
		}
	}
	cat ans = 0;
	ALL_THE(live, it) {
		ans += cnt[*it];
		if(ans >= mod) ans -= mod;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
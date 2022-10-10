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

cat mod = 998244353;

vector<cat> prod1l(300000), prod1r(300000);

void DFS(int R, vector< vector<int> > & son, vector<int> & par, vector< pair<cat, cat> > & cnt) {
	if(son[R].empty()) {
		cnt[R] = {1, 1};
		return;
	}
	// cnt[R].ss = neide cesta hore
	// cnt[R].ff = ide cesta hore, musi ist aspon jedna zdola
	cat prod0 = 1, prod = 1;
	ALL_THE(son[R], it) {
		DFS(*it, son, par, cnt);
		prod0 = (prod0 * cnt[*it].ss) % mod;
		prod = (prod * (cnt[*it].ss + cnt[*it].ff)) % mod;
	}
	cnt[R].ff = (prod - prod0) % mod;
	int D = son[R].size();
	prod1l[0] = prod1r[D] = 1;
	for(int i = 0; i < D; i++)
		prod1l[i+1] = prod1l[i] * cnt[son[R][i]].ss % mod;
	for(int i = 0; i < D; i++)
		prod1r[D-1-i] = prod1r[D-i] * cnt[son[R][D-1-i]].ss % mod;
	cat sum1 = 0;
	for(int i = 0; i < D; i++)
		sum1 = (sum1 + prod1l[i] * prod1r[i+1] % mod * cnt[son[R][i]].ff) % mod;
	cnt[R].ss = (prod - sum1) % mod;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> par(N, 0);
	vector< vector<int> > son(N);
	for(int i = 0; i < N-1; i++) {
		int p;
		cin >> p;
		par[i+1] = --p;
		son[p].push_back(i+1);
	}
	vector< pair<cat, cat> > cnt(N);
	DFS(0, son, par, cnt);
	cnt[0].ss %= mod;
	if(cnt[0].ss < 0) cnt[0].ss += mod;
	cout << cnt[0].ss << "\n";
	return 0;
}

// look at my code
// my code is amazing
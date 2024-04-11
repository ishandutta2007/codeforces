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
	int N, Q;
	cin >> N >> Q;
	vector< vector<int> > lst[15];
	for(int i = 0; i < 15; i++) lst[i].resize(N);
	const int B = 60;
	for(int i = 0; i < Q; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		l--;
		while(l < r) {
			int k = 0;
			while(l+(1<<(k+1)) <= r && ((l>>k)&1) == 0) k++;
			lst[k][l].push_back(x);
			l += 1<<k;
		}
	}
	vector< vector<cat> > ans(1, vector<cat>(N/B+3, 0));
	ans[0][0] = 1;
	int sz = 1;
	for(int k = 14; k > 0; k--) {
		vector< vector<cat> > ans_nw(2*sz);
		for(int i = 0; i < sz; i++)
			ans_nw[2*i] = ans_nw[2*i+1] = ans[i];
		sz *= 2;
		while((sz-1) * (1<<(k-1)) >= N) sz--;
		for(int i = 0; i < N; i += (1<<(k-1))) ALL_THE(lst[k-1][i], it) {
			int id = i / (1<<(k-1));
			for(int j = N/B+1-(*it/B); j >= 0; j--) {
				ans_nw[id][j] &= (1LL<<60)-1;
				ans_nw[id][j+(*it/B)+1] |= ans_nw[id][j]>>(B-*it%B);
				ans_nw[id][j+(*it/B)] |= ans_nw[id][j]<<(*it%B);
			}
		}
		ans = ans_nw;
	}
	vector<cat> ans_tot = ans[0];
	for(int i = 1; i < (int)ans.size(); i++)
		for(int j = 0; j < (int)ans_tot.size(); j++)
			ans_tot[j] |= ans[i][j];
	vector<int> ans_lst;
	for(int i = 1; i <= N; i++) if((ans_tot[i/B]>>(i%B))&1)
		ans_lst.push_back(i);
	cout << ans_lst.size() << "\n";
	for(int i = 0; i < (int)ans_lst.size(); i++)
		cout << ans_lst[i] << ((i+1 == (int)ans_lst.size())?"\n":" ");
	return 0;}

// look at my code
// my code is amazing
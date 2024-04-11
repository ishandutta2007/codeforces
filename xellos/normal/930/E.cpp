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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat mod =1000000007;

int clean(vector< pair<int, int> > &I) {
	for(int i = 0; i < (int)I.size(); i++) {
		swap(I[i].ff, I[i].ss);
		I[i].ss *= -1;
	}
	sort(begin(I), end(I));
	for(int i = 0; i < (int)I.size(); i++) {
		I[i].ss *= -1;
		swap(I[i].ff, I[i].ss);
	}
	vector< pair<int, int> > I_nw;
	int lastb = -1;
	for(int i = 0; i < (int)I.size(); i++) {
		if(lastb < I[i].ff) I_nw.push_back(I[i]);
		lastb = max(lastb, I[i].ff);
	}
	I = I_nw;
	return I_nw.size();
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = (x * x)%mod;
	if(e%2) x = (x * a)%mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int K, N[2];
	cin >> K >> N[0] >> N[1];
	vector< pair<int, int> > I[2];
	map<int, int> M;
	M[0] = M[K] = 0;
	for(int k = 0; k < 2; k++) {
		I[k].resize(N[k]);
		for(int i = 0; i < N[k]; i++) {
			cin >> I[k][i].ff >> I[k][i].ss;
			I[k][i].ff--;
		}
		N[k] = clean(I[k]);
		for(int i = 0; i < N[k]; i++)
			M[I[k][i].ff] = M[I[k][i].ss] = 0;
	}

	int m = 0, last = 0;
	vector<int> len;
	vector<cat> cnt;
	ALL_THE(M, it) {
		it->ss = m++;
		if(it->ff != last) len.push_back(it->ff-last);
		last = it->ff;
	}
	int L = len.size();
	cnt.resize(L);
	for(int i = 0; i < L; i++) cnt[i] = (pw(2, len[i], mod) + mod - 2) % mod;
	for(int k = 0; k < 2; k++) for(int i = 0; i < N[k]; i++) {
		I[k][i].ff = M[I[k][i].ff];
		I[k][i].ss = M[I[k][i].ss];
	}

	vector<cat> ans[3]; // ends with 0, 1, 0&1
	for(int k = 0; k < 3; k++) ans[k].resize(L+1, 0);
	ans[2][0] = 1;
	vector<cat> sum_ans[3];
	for(int k = 0; k < 3; k++) sum_ans[k].resize(L+1, 0);

	int pos[2] = {0, 0}, last_st[2] = {-1, -1};
	for(int i = 0; i < L; i++) {
		for(int k = 0; k < 3; k++) sum_ans[k][i+1] = (sum_ans[k][i]+ans[k][i]) % mod;
		ans[2][i+1] = (ans[0][i]+ans[1][i]+ans[2][i]) * cnt[i] % mod;
		for(int k = 0; k < 2; k++) {
			while(pos[1-k] < N[1-k] && I[1-k][pos[1-k]].ss <= i+1) {
				last_st[1-k] = I[1-k][pos[1-k]].ff;
				pos[1-k]++;
			}
			ans[k][i+1] = (sum_ans[2][i+1]-sum_ans[2][last_st[1-k]+1] + sum_ans[1-k][i+1]-sum_ans[1-k][last_st[1-k]+1]) % mod;
		}
	}

	cat ansF = (ans[0][L]+ans[1][L]+ans[2][L])%mod;
	if(ansF < 0) ansF += mod;
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing
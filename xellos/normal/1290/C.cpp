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
	int N, K;
	string S;
	cin >> N >> K >> S;
	vector< vector<int> > sub(N);
	for(int i = 0; i < K; i++) {
		int c;
		cin >> c;
		for(int j = 0; j < c; j++) {
			int a;
			cin >> a;
			sub[--a].push_back(i);
		}
	}
	vector< vector<int> > comp(2*K);
	map<int, int> comp2;
	vector<int> in_comp(K);
	for(int i = 0; i < K; i++) in_comp[i] = i, comp[i] = {i};
	for(int i = 0; i < K; i++) comp2[i+K] = i, comp2[i] = i+K;
	vector<char> state(2*K, 0); // unfixed
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(sub[i].empty()) {
			cout << ans << "\n";
			continue;
		}
		if(sub[i].size() == 1) {
			// fix state
			int st = (S[i] == '0');
			int c = in_comp[sub[i][0]];
			if(!state[c]) {
				int c2 = comp2[c];
				ans -= min(comp[c].size(), comp[c2].size());
				state[c] = 1+2*st;
				state[c2] = 1+2*(1-st);
				ans += st ? comp[c].size() : comp[c2].size();
			}
			cout << ans << "\n";
			continue;
		}
		int c0 = in_comp[sub[i][0]], c1 = in_comp[sub[i][1]];
		int c20 = comp2[c0], c21 = comp2[c1];
		if(S[i] == '0') swap(c1, c21);
		// c0 + c1, c20 + c21
		if(c0 == c1) {
			cout << ans << "\n";
			continue;
		}
		if(state[c0]) ans -= (state[c0] == 3) ? comp[c0].size() : comp[c20].size();
		else ans -= min(comp[c0].size(), comp[c20].size());
		if(state[c1]) ans -= (state[c1] == 3) ? comp[c1].size() : comp[c21].size();
		else ans -= min(comp[c1].size(), comp[c21].size());
		// make component
		if(comp[c0].size() < comp[c1].size()) {
			swap(c0, c1);
			swap(c20, c21);
		}
		for(auto x : comp[c1]) {
			in_comp[x] = c0;
			comp[c0].push_back(x);
		}
		if(comp[c20].size() < comp[c21].size()) {
			comp2[c0] = c21;
			comp2[c21] = c0;
			swap(c20, c21);
		}
		for(auto x : comp[c21]) {
			in_comp[x] = c20;
			comp[c20].push_back(x);
		}
		// propagate state
		state[c0] |= state[c1];
		state[c20] |= state[c21];
		if(state[c0]) state[c20] = state[c0] ^ 2;
		if(state[c20]) state[c0] = state[c20] ^ 2;
		if(state[c0])
			ans += (state[c0] == 3) ? comp[c0].size() : comp[c20].size();
		else
			ans += min(comp[c0].size(), comp[c20].size());
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
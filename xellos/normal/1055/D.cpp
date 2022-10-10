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
	vector<string> Wo(N), Wt(N);
	for(int i = 0; i < N; i++) cin >> Wo[i];
	for(int i = 0; i < N; i++) cin >> Wt[i];
	string orig = "", repl = "";
	vector<int> pos(N, -1);
	for(int i = 0; i < N; i++) {
		int L = Wo[i].length();
		for(int j = 0; j < L; j++) if(Wo[i][j] != Wt[i][j]) {
			int k = L-1;
			while(Wo[i][k] == Wt[i][k]) k--;
			string orig_cur = Wo[i].substr(j, k-j+1);
			string repl_cur = Wt[i].substr(j, k-j+1);
			if(orig == "") {
				orig = orig_cur;
				repl = repl_cur;
			}
			if(orig != orig_cur || repl != repl_cur) {
				cout << "NO\n";
				return 0;
			}
			pos[i] = j;
			break;
		}
	}
	int L = orig.length();
	while(true) {
		char c;
		for(int i = 0; i < N; i++) if(pos[i] > 0) c = Wo[i][pos[i]-1];
		bool ext = true;
		for(int i = 0; i < N; i++) if(pos[i] == 0) {
			ext = false;
			break;
		}
		for(int i = 0; i < N; i++) if(pos[i] > 0 && c != Wo[i][pos[i]-1]) {
			ext = false;
			break;
		}
		if(!ext) break;
		for(int i = 0; i < N; i++) if(pos[i] > 0) pos[i]--;
		L++;
	}
	while(true) {
		char c;
		for(int i = 0; i < N; i++) if(pos[i] >= 0 && pos[i]+L < (int)Wo[i].length()) c = Wo[i][pos[i]+L];
		bool ext = true;
		for(int i = 0; i < N; i++) if(pos[i] >= 0 && pos[i]+L == (int)Wo[i].length()) {
			ext = false;
			break;
		}
		for(int i = 0; i < N; i++) if(pos[i] >= 0 && pos[i]+L < (int)Wo[i].length() && c != Wo[i][pos[i]+L]) {
			ext = false;
			break;
		}
		if(!ext) break;
		L++;
	}
	for(int i = 0; i < N; i++) if(pos[i] >= 0) {
		orig = Wo[i].substr(pos[i], L);
		repl = Wt[i].substr(pos[i], L);
	}
	vector<int> prev(L+1, 0);
	for(int j = 2; j <= L; j++) {
		while(prev[j] > 0 && orig[j-1] == orig[prev[j]]) prev[j] = prev[prev[j]];
		if(orig[j-1] == orig[prev[j]]) prev[j]++;
	}
	for(int i = 0; i < N; i++) {
		int Lc = Wo[i].length();
		int cur = 0;
		for(int j = 0; j < Lc; j++) {
			while(cur > 0 && Wo[i][j] != orig[cur]) cur = prev[cur];
			if(Wo[i][j] == orig[cur]) cur++;
			if(cur == L) {
				if(j != pos[i]+L-1) {
					cout << "NO\n";
					return 0;
				}
				break;
			}
		}
	}
	cout << "YES\n";
	cout << orig << "\n";
	cout << repl << "\n";
	return 0;
}

// look at my code
// my code is amazing
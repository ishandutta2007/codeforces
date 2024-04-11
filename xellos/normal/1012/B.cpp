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
	int R, C, N;
	cin >> R >> C >> N;
	if(N == 0) {
		cout << R+C-1 << "\n";
		return 0;
	}
	vector<int> cntr(R, 0), cntc(C, 0);
	vector< vector<int> > inr(R), inc(C);
	for(int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		cntr[--r]++;
		cntc[--c]++;
		inr[r].push_back(c);
		inc[c].push_back(r);
	}
	int ans = 0;
	for(int i = 0; i < R; i++) if(cntr[i] == 0) ans++;
	for(int i = 0; i < C; i++) if(cntc[i] == 0) ans++;
	vector< vector<int> > G(R+C);
	for(int i = 0; i < R; i++) for(int j = 1; j < (int)inr[i].size(); j++) {
		G[inr[i][j]+R].push_back(inr[i][j-1]+R);
		G[inr[i][j-1]+R].push_back(inr[i][j]+R);
	}
	for(int i = 0; i < C; i++) for(int j = 1; j < (int)inc[i].size(); j++) {
		G[inc[i][j]].push_back(inc[i][j-1]);
		G[inc[i][j-1]].push_back(inc[i][j]);
	}
	vector<bool> vis(R+C, 0);
	queue<int> q;
	for(int i = 0; i < R; i++) if(cntr[i] && !vis[i]) {
		vis[i] = true;
		q.push(i);
		while(!q.empty()) {
			ALL_THE(G[q.front()], it) if(!vis[*it]) {
				vis[*it] = true;
				q.push(*it);
			}
			q.pop();
		}
		ans++;
	}
	ans--;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
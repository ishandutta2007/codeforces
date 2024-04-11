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

struct line {
	int x1, y1, x2, y2;
};

void DFS(int v, vector< vector<int> > & G, vector< vector<int> > & F, vector<int> & back) {
	ALL_THE(G[v], it) if(back[*it] == -1 && F[v][*it] == 1) {
		back[*it] = v;
		DFS(*it, G, F, back);
		if(back.back() != -1) break;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<int, int> > P(N);
	for(int i = 0; i < N; i++)
		cin >> P[i].ff >> P[i].ss;
	vector<int> nxtx(N), nxty(N);
	for(int i = 0; i < N; i++) {
		int miny = OVER9000, minid = -1;
		for(int j = 0; j < N; j++) if(P[i].ff == P[j].ff && P[j].ss > P[i].ss && P[j].ss < miny) {
			miny = P[j].ss;
			minid = j;
		}
		nxtx[i] = minid;
	}
	for(int i = 0; i < N; i++) {
		int minx = OVER9000, minid = -1;
		for(int j = 0; j < N; j++) if(P[i].ss == P[j].ss && P[j].ff > P[i].ff && P[j].ff < minx) {
			minx = P[j].ff;
			minid = j;
		}
		nxty[i] = minid;
	}
	vector< vector<int> > F(2*N+2, vector<int>(2*N+2, 0));
	vector< vector<int> > G(2*N+2);
	for(int i = 0; i < N; i++) {
		F[0][i+1] = 1;
		G[i+1].push_back(0);
		G[0].push_back(i+1);
	}
	for(int i = 0; i < N; i++) {
		F[N+1+i][2*N+1] = 1;
		G[N+1+i].push_back(2*N+1);
		G[2*N+1].push_back(N+1+i);
	}
	for(int i = 0; i < N; i++) if(nxtx[i] != -1)
		for(int j = 0; j < N; j++) if(nxty[j] != -1)
			if(P[i].ss < P[j].ss && P[nxtx[i]].ss > P[j].ss && P[j].ff < P[i].ff && P[nxty[j]].ff > P[i].ff) {
				F[i+1][N+1+j] = 1;
				G[i+1].push_back(N+1+j);
				G[N+1+j].push_back(i+1);
			}
	int mdif = 0;
	while(true) {
		vector<int> back(2*N+2, -1);
		back[0] = 0;
		DFS(0, G, F, back);
		if(back[2*N+1] == -1) break;
		mdif++;
		int akt = 2*N+1;
		while(akt != 0) {
			swap(F[back[akt]][akt], F[akt][back[akt]]);
			akt = back[akt];
		}
	}
	queue<int> q;
	vector<bool> reach(2*N+2, false);
	reach[0] = true;
	q.push(0);
	while(!q.empty()) {
		for(int i = 0; i < 2*N+1; i++) if(!reach[i] && F[q.front()][i]) {
			reach[i] = true;
			q.push(i);
		}
		q.pop();
	}
	vector<bool> extendx(N, false), extendy(N, false);
	for(int i = 0; i < N; i++) if(reach[i+1]) extendx[i] = true;
	for(int i = 0; i < N; i++) if(!reach[N+1+i]) extendy[i] = true;
	for(int i = 0; i < N; i++) if(!extendx[i]) mdif--;
	for(int i = 0; i < N; i++) if(!extendy[i]) mdif--;
	if(mdif != 0) return 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(extendx[i] && extendy[j] && F[i+1][N+1+j]+F[N+1+j][i+1] == 1) return 0;
	vector<line> ansh, ansv;
	for(int i = 0; i < N; i++) if(!extendx[i] || nxtx[i] == -1) {
		int maxx = 0, minx = OVER9000;
		for(int j = 0; j < N; j++) if(P[i].ff == P[j].ff && P[j].ss < P[i].ss && !extendx[j]) maxx = max(maxx, P[j].ss);
		for(int j = 0; j < N; j++) if(P[i].ff == P[j].ff && P[j].ss <= P[i].ss && P[j].ss > maxx) minx = min(minx, P[j].ss);
		ansv.push_back({P[i].ff, minx, P[i].ff, P[i].ss});
	}
	for(int i = 0; i < N; i++) if(!extendy[i] || nxty[i] == -1) {
		int maxy = 0, miny = OVER9000;
		for(int j = 0; j < N; j++) if(P[i].ss == P[j].ss && P[j].ff < P[i].ff && !extendy[j]) maxy = max(maxy, P[j].ff);
		for(int j = 0; j < N; j++) if(P[i].ss == P[j].ss && P[j].ff <= P[i].ff && P[j].ff > maxy) miny = min(miny, P[j].ff);
		ansh.push_back({miny, P[i].ss, P[i].ff, P[i].ss});
	}
	cout << ansh.size() << "\n";
	for(int i = 0; i < (int)ansh.size(); i++) cout << ansh[i].x1 << " " << ansh[i].y1 << " " << ansh[i].x2 << " " << ansh[i].y2 << "\n";
	cout << ansv.size() << "\n";
	for(int i = 0; i < (int)ansv.size(); i++) cout << ansv[i].x1 << " " << ansv[i].y1 << " " << ansv[i].x2 << " " << ansv[i].y2 << "\n";
	return 0;
}

// look at my code
// my code is amazing
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

void DFS(int R, int par, auto & E, auto & G, auto & dir) {
	int last = -1;
	for(auto e : G[R]) if(par != E[e]) {
		DFS(E[e], R, E, G, dir);
		if(dir[e/2] != -1) continue;
		if(last == -1) last = e;
		else {
			cout << "? " << E[last]+1 << " " << E[e]+1 << endl;
			int a;
			cin >> a;
			a--;
			dir[e/2] = (e&1)^1;
			dir[last/2] = (last&1)^1;
			if(a == E[last]) dir[last/2] ^= 1;
			if(a == E[e]) dir[e/2] ^= 1;
			last = -1;
		}
	}
	if(last != -1 && R) {
		int e_par = -1;
		for(auto e : G[R]) if(par == E[e]) e_par = e;
		cout << "? " << E[last]+1 << " " << par+1 << endl;
		int a;
		cin >> a;
		a--;
		dir[last/2] = (last&1)^1;
		dir[e_par/2] = (e_par&1)^1;
		if(a == E[last]) dir[last/2] ^= 1;
		if(a == par) dir[e_par/2] ^= 1;
	}
	else if(last != -1) {
		cout << "? " << R+1 << " " << E[last]+1 << endl;
		int a;
		cin >> a;
		a--;
		if(a == E[last]) dir[last/2] = last&1;
		else dir[last/2] = (last&1)^1;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> E(2*(N-1));
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		E[2*i] = --u, E[2*i+1] = --v;
		G[v].push_back(2*i);
		G[u].push_back(2*i+1);
	}
	vector<int> dir(N-1, -1);
	DFS(0, 0, E, G, dir);
	vector<int> cnt_out(N, 0);
	for(int i = 0; i < N-1; i++) cnt_out[E[2*i+1-dir[i]]]++;
	for(int i = 0; i < N; i++) if(cnt_out[i] == 0) {
		cout << "! " << i+1 << endl;
		return 0;
	}
	return 0;
}

// look at my code
// my code is amazing
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

void swap(int a, int b, auto & P, auto & P_inv, auto & ans) {
	if(a == b) return;
	int va = P[a], vb = P[b];
	ans.push_back({a, b});
	swap(P[a], P[b]);
	swap(P_inv[va], P_inv[vb]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> P(N), inv(N);
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		inv[--P[i]] = i;
	}
	vector< pair<int, int> > ans;
	for(int i = 0; i < N/2; i++) {
		if(i == N/2-1) {
			if(P[0]) ans.push_back({0, N-1});
			break;
		}
		int id_l = inv[N/2-1-i], val_l = N/2-1-i;
		if(id_l != val_l) {
			if(id_l < N/2) {
				swap(id_l, N-1, P, inv, ans);
				swap(N-1, val_l, P, inv, ans);
			}
			else {
				swap(id_l, 0, P, inv, ans);
				swap(0, N-1, P, inv, ans);
				swap(N-1, val_l, P, inv, ans);
			}
		}
		int id_r = inv[N/2+i], val_r = N/2+i;
		if(id_r != val_r) {
			if(id_r < N/2) {
				swap(id_r, N-1, P, inv, ans);
				swap(N-1, 0, P, inv, ans);
				swap(0, val_r, P, inv, ans);
			}
			else {
				swap(id_r, 0, P, inv, ans);
				swap(0, val_r, P, inv, ans);
			}
		}
	}
	cout << ans.size() << "\n";
	for(auto p : ans) cout << p.ff+1 << " " << p.ss+1 << "\n";
	return 0;
}

// look at my code
// my code is amazing
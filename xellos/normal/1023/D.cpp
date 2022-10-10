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
	vector<int> A(N);
	bool has_max = false, has_zero = false;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		if(A[i] == 0) has_zero = true;
		if(A[i] == Q) has_max = true;
	}
	if(!has_max && !has_zero) {
		cout << "NO\n";
		return 0;
	}
	if(!has_max) for(int i = 0; i < N; i++) if(A[i] == 0) {
		A[i] = Q;
		break;
	}
	for(int i = 0; i < N; i++) if(A[i] == 0 && i > 0 && A[i-1] != 0) A[i] = A[i-1];
	for(int i = N-2; i >= 0; i--) if(A[i] == 0 && A[i+1] != 0) A[i] = A[i+1];
	vector< vector<int> > pos_val(Q);
	for(int i = 0; i < N; i++) {
		A[i]--;
		pos_val[A[i]].push_back(i);
	}
	set<int> free_pos;
	for(int i = 0; i < N; i++) free_pos.insert(i);
	for(int i = Q-1; i >= 0; i--) {
		if(pos_val[i].empty()) continue;
		int mii = pos_val[i][0], mxi = pos_val[i].back();
		auto it = free_pos.lower_bound(mii);
		while(true) {
			if(it == free_pos.end() || *it > mxi) break;
			auto jt = it;
			it++;
			if(A[*jt] < i) {
				cout << "NO\n";
				return 0;
			}
			free_pos.erase(jt);
		}
	}
	cout << "YES\n";
	for(int i = 0; i < N; i++) cout << A[i]+1 << ((i == N-1)?"\n":" ");
	return 0;
}

// look at my code
// my code is amazing
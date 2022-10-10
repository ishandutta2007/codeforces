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
	/*
	y na zaciatku v abs. hodnote
	pride x > y v abs. hodnote:
		vsetky < x obratia znamienka: flip
		vsetky < -x obratia znamienka: nic
		vsetky > x obratia znamienka: nic
		vsetky > -x obratia znamienka: flip
	pride x == y v abs. hodnote:
		vsetky < x obratia znamienka: bude +
		vsetky < -x obratia znamienka: nic
		vsetky > x obratia znamienka: nic
		vsetky > -x obratia znamienka: bude -
	pride x < y v abs. hodnote:
		vsetky < x obratia znamienka: bude +
		vsetky < -x obratia znamienka: bude +
		vsetky > x obratia znamienka: bude -
		vsetky > -x obratia znamienka: bude -

	< -, > +
		vsetky < -x obratia znamienka:
			x >= y: nic
			x < y: bude +
		vsetky > x obratia znamienka:
			x >= y: nic
			x < y: bude -

	< +, > -
	pride x > y v abs. hodnote:
		vsetky < x obratia znamienka:
			x > y: flip
			x <= y: bude +
		vsetky > -x obratia znamienka:
			x > y: flip
			x <= y: bude -

	*/
	int N, Q;
	cin >> N >> Q;
	vector< pair<int, pair<int, int> > > A(N);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i].ff = abs(a);
		if(a == 0) A[i].ss = {0, i};
		else A[i].ss = {a/A[i].ff, i};
	}
	sort(begin(A), end(A));
	vector< pair<int, int> > qu(Q);
	for(int i = 0; i < Q; i++) {
		string s;
		cin >> s >> qu[i].ss;
		qu[i].ff = (s == ">") ? 1 : -1;
	}
	vector<int> fix_sign(N, 0), fix_q(N, 0);
	for(int i = 0; i < N; i++) fix_sign[i] = A[i].ss.ff;
	int last_fix = N-1;
	for(int q = Q-1; q >= 0; q--) {
		int type = 0;
		if(qu[q].ff == -1 && qu[q].ss >= 0) type = 1;
		if(qu[q].ff ==  1 && qu[q].ss <= 0) type = 1;
		if(type == 0) while(last_fix >= 0 && A[last_fix].ff > abs(qu[q].ss)) {
			fix_sign[last_fix] = -qu[q].ff;
			fix_q[last_fix] = q+1;
			last_fix--;
		}
		if(type == 1) while(last_fix >= 0 && A[last_fix].ff >= abs(qu[q].ss)) {
			fix_sign[last_fix] = -qu[q].ff;
			fix_q[last_fix] = q+1;
			last_fix--;
		}
	}
	for(int i = 0; i < N; i++) A[i].ss.ff = fix_sign[i];
	int first_e = 0;
	vector<int> A_arr(N);
	for(int i = 0; i < N; i++) A_arr[i] = A[i].ff;
	vector<int> flips(N, 0);
	for(int q = 0; q < Q; q++) {
		int type = 0;
		if(qu[q].ff == -1 && qu[q].ss >= 0) type = 1;
		if(qu[q].ff ==  1 && qu[q].ss <= 0) type = 1;
		if(type == 0) continue;
		while(first_e < N && fix_q[first_e] < q+1) first_e++;
		int max_id = lower_bound(begin(A_arr), end(A_arr), abs(qu[q].ss)) - begin(A_arr) - 1;
		max_id = min(max_id, first_e-1);
		if(max_id >= 0) flips[max_id] ^= 1;
	}
	for(int i = N-1; i > 0; i--) flips[i-1] ^= flips[i];
	for(int i = 0; i < N; i++) if(flips[i]) A[i].ss.ff *= -1;
	vector<int> ans(N);
	for(int i = 0; i < N; i++) {
		ans[A[i].ss.ss] = A[i].ff;
		if(A[i].ss.ff == -1) ans[A[i].ss.ss] *= -1;
	}
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
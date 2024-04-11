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

cat solve(const int * __restrict A, int N) {
	if(N <= 1) return 0;
	cat cnt = 0;
	{
		vector<int> Vl(N/2+1, 0), Vr(N-N/2+1, 0);
		int nl = 1, nr = 1;
		vector< unordered_map<int, int> > nextl(1), nextr(1);
		{
			vector<int> par(1, 0);
			stack<int> Sr;
			for(int i = N/2, cur = 0; i < N; i++) {
				if(!Sr.empty() && Sr.top() == A[i]) {
					cur = Vr[i-N/2+1] = par[cur];
					Sr.pop();
				}
				else {
					if(auto it = nextr[cur].find(A[i]); it != end(nextr[cur]))
						cur = Vr[i-N/2+1] = it->ss;
					else {
						nextr[cur][A[i]] = nr;
						par.push_back(cur);
						nextr.push_back({});
						cur = Vr[i-N/2+1] = nr;
						nr++;
					}
					Sr.push(A[i]);
				}
			}
		}
		vector<int> par(1, 0);
		stack<int> Sl;
		for(int i = N/2-1, cur = 0; i >= 0; i--) {
			if(!Sl.empty() && Sl.top() == A[i]) {
				cur = Vl[i] = par[cur];
				Sl.pop();
			}
			else {
				if(auto it = nextl[cur].find(A[i]); it != end(nextl[cur]))
					cur = Vl[i] = it->ss;
				else {
					nextl[cur][A[i]] = nl;
					par.push_back(cur);
					nextl.push_back({});
					cur = Vl[i] = nl;
					nl++;
				}
				Sl.push(A[i]);
			}
		}
		vector<int> eq_state(nr, -1);
		eq_state[0] = 0;
		for(int i = 0; i < nr; i++) if(eq_state[i] != -1)
			for(auto p : nextr[i]) if(auto it = nextl[eq_state[i]].find(p.ff); it != end(nextl[eq_state[i]]))
				eq_state[p.ss] = it->ss;
		vector<int> cntl(nl, 0), cntr(nr, 0);
		for(int i = 0; i < N/2; i++) cntl[Vl[i]]++;
		for(int i = 1; i <= N-N/2; i++) cntr[Vr[i]]++;
		for(int i = 0; i < nr; i++) if(eq_state[i] != -1)
			cnt += 1LL*cntl[eq_state[i]] * cntr[i];
	}
	return cnt + solve(A, N/2) + solve(A+N/2, N-N/2);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		cout << solve(A.data(), N) << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
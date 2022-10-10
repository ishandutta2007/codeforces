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
	vector< pair<cat, cat> > A(N);
	for(int i = 0; i < N; i++) cin >> A[i].ss >> A[i].ff;
	cat sum = 0;
	for(int i = 0; i < N; i++) sum += A[i].ss;
	if(sum < 0) {
		for(int i = 0; i < N; i++) A[i].ss *= -1;
		sum *= -1;
	}
	cat ans = 0, live = 0;
	for(int i = 0; i < N; i++) live |= A[i].ff;
	for(int k = 0; k < 62; k++) if(!A.empty() && live && sum >= 0) {
		sort(begin(A), end(A));
		for(int i = 0, a = 0; i < N; i++) {
			if(i > a && A[i].ff == A[a].ff) A[a].ss += A[i].ss;
			if(A[i].ff != A[a].ff) A[++a] = A[i];
			if(i == N-1) N = a+1;
		}
		A.resize(N);
		int b = -1;
		for(int i = 0; i < N; i++) if(!(A[i].ff & (A[i].ff-1))) {
			cat p = A[i].ff;
			b = 0;
			while(p > 1) p /= 2, b++;
			break;
		}
		if(b == -1) {
			b = 0;
			while(!((live>>b)&1)) b++;
			live ^= 1LL<<b;
			for(int i = 0; i < N; i++) if((A[i].ff>>b)&1) A[i].ff ^= 1LL<<b;
			continue;
		}
		live ^= 1LL<<b;
		for(int i = 0; i < N; i++) if(A[i].ff == (1LL<<b)) {
			if(A[i].ss > 0) {
				ans ^= 1LL<<b;
				for(int j = 0; j < N; j++) if((A[j].ff>>b)&1) {
					sum -= 2 * A[j].ss;
					A[j].ss *= -1;
				}
			}
			A.erase(begin(A)+i);
			N--;
			break;
		}
		for(int i = 0; i < N; i++) if((A[i].ff>>b)&1) A[i].ff ^= 1LL<<b;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
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
#include <random>
#include <chrono>
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
	int T;
	cin >> T;
	while(T--) {
		cat N, M, K;
		cin >> N >> M >> K;
		K += M+1;
		vector<cat> A(M+1);
		cat last = 0, cur;
		for(int i = 0; i <= M; i++) {
			if(i < M) cin >> cur;
			else cur = N;
			A[i] = cur-last;
			last = cur;
		}
		// answer 0?
		if(N%K == 0) {
			cat v = N/K;
			bool ok = true;
			for(int i = 0; i <= M; i++) if(A[i]%v) ok = false;
			if(ok) {
				cout << "0\n";
				continue;
			}
		}
		// answer > 0
		cat l_mi = 0, l_mx = N+1;
		while(l_mx-l_mi > 1) {
			cat l = (l_mi + l_mx) / 2, val = 0;
			for(int i = 0; i <= M; i++) val += A[i]/l;
			if(val >= K) l_mi = l;
			else l_mx = l;
		}
		for(int i = 0; i <= M; i++) l_mi = min(l_mi, A[i]);
		cat r_mi = 0, r_mx = N+1;
		while(r_mx-r_mi > 1) {
			cat r = (r_mi + r_mx) / 2, val = 0;
			for(int i = 0; i <= M; i++) val += (A[i]+r-1)/r;
			if(val <= K) r_mx = r;
			else r_mi = r;
		}
		cat l0 = l_mi, r0 = r_mx;
		vector< pair<cat, cat> > LR;
		for(int i = 0; i <= M; i++) if((A[i]+r0-1)/r0 > A[i]/l0) {
			cat v = (A[i] + r0-1) / r0;
			l_mi = 0, l_mx = l0;
			while(l_mx-l_mi > 1) {
				cat l = (l_mi + l_mx) / 2;
				if(A[i] / l >= v) l_mi = l;
				else l_mx = l;
			}
			v = A[i] / l0;
			r_mi = r0, r_mx = max(r0, A[i]) + 1;
			while(r_mx-r_mi > 1) {
				cat r = (r_mi + r_mx) / 2;
				if((A[i] + r-1) / r <= v) r_mx = r;
				else r_mi = r;
			}
			LR.push_back({l_mi, r_mx});
		}
		if(LR.empty()) {
			cout << r0-l0 << "\n";
			continue;
		}
		sort(begin(LR), end(LR));
		cat D = r0-begin(LR)->ff, r = r0;
		for(int i = 0; i < (int)LR.size(); i++) {
			r = max(r, LR[i].ss);
			cat l = l0;
			if(i+1 < (int)LR.size()) l = LR[i+1].ff;
			D = min(D, r-l);
		}
		cout << D << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
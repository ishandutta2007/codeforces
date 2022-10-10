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
#define OVER9000 1234567890123456789LL
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
	vector<cat> A(N), B(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] *= 1000;
	}
	for(int i = 0; i < N; i++) cin >> B[i];
	cat kmin = 0, kmax = 10000000000000LL;
	while(kmax-kmin > 1) {
		cat K = (kmin+kmax) / 2;
		vector< pair<cat, cat> > C(N);
		for(int i = 0; i < N; i++) {
			C[i].first = A[i];
			C[i].second = B[i] * K - A[i];
		}
		sort(begin(C), end(C));
		vector<cat> V(N+1, -OVER9000);
		V[0] = 0;
		for(int i = N-1; i >= 0; i--) {
			int d = i;
			vector<cat> V_nw(N+1, -OVER9000);
			vector<cat> D;
			while(d >= 0 && C[d].first == C[i].first) {
				D.push_back(C[d].second);
				d--;
			}
			sort(begin(D), end(D));
			reverse(begin(D), end(D));
			int dn = D.size();
			vector<cat> Ds(dn+1, 0);
			for(int j = 0; j < dn; j++) Ds[j+1] = Ds[j] + D[j];
			for(int j = 0; j <= dn; j++) for(int k = dn-j; k <= N; k++) if(V[k] > -OVER9000)
				V_nw[k-(dn-j)+j] = max(V_nw[k-(dn-j)+j], V[k] + Ds[j]);
			V = V_nw;
			i = d+1;
		}
		bool ok = false;
		for(int i = 0; i <= N; i++) if(V[i] >= 0) ok = true;
		if(ok) kmax = K;
		else kmin = K;
	}
	cout << kmax << "\n";
	return 0;}

// look at my code
// my code is amazing
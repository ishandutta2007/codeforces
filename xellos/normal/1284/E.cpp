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

struct pt {
	cat x, y;

	pt operator+(pt P) const { return {x+P.x, y+P.y}; }
	pt operator-(pt P) const { return {x-P.x, y-P.y}; }
	cat operator*(pt P) { return x*P.x+y*P.y; }
	cat operator^(pt P) { return x*P.y-y*P.x; }
	dbl get_cos(pt P) { return (*this)*P/sqrt((dbl)(P*P)); }
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<pt> V(N);
	for(int i = 0; i < N; i++) cin >> V[i].x >> V[i].y;
	cat cnt = 0;
	for(int i = 0; i < N; i++) {
		vector< pair<dbl, int> > S[2];
		int c = i ? 0 : 1;
		pt Vc = V[c]-V[i];
		for(int j = 0; j < N; j++) if(i != j && c != j)
			S[(Vc^(V[j]-V[i])) > 0].push_back({Vc.get_cos(V[j]-V[i]), j});
		sort(begin(S[0]), end(S[0]));
		sort(begin(S[1]), end(S[1]));
		cnt += S[0].size()*S[1].size();
		reverse(begin(S[0]), end(S[0]));
		for(int j = 0, a = 0, n = S[1].size()+1; j < (int)S[0].size(); j++, n++) {
			pt V1 = V[S[0][j].ss]-V[i];
			while(a < (int)S[1].size() && (V1^(V[S[1][a].ss]-V[i])) < 0) a++, n--;
			cnt += n*(N-2-n);
		}
		reverse(begin(S[0]), end(S[0]));
		reverse(begin(S[1]), end(S[1]));
		for(int j = 0, a = 0, n = S[0].size()+1; j < (int)S[1].size(); j++, n++) {
			pt V1 = V[S[1][j].ss]-V[i];
			while(a < (int)S[0].size() && (V1^(V[S[0][a].ss]-V[i])) > 0) a++, n--;
			cnt += n*(N-2-n);
		}
	}
	cout << (cnt/2 - 1LL*N*(N-1)*(N-2)*(N-3)/12) * (N-4) / 2 << "\n";
	return 0;
}

// look at my code
// my code is amazing
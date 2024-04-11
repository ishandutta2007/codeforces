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
	int N, K, MX = 100000, S = 317;
	cin >> N >> K;
	vector<int> sp;
	for(int i = 2; i < S; i++) {
		bool pr = true;
		for(int j = 2; j < i; j++) if(i%j == 0) pr = false;
		if(pr) sp.push_back(i);
	}
	vector< vector< vector<int> > > A(MX+1);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vector<int> e(sp.size(), 0);
		for(int j = 0; j < (int)sp.size(); j++)
			while(a%sp[j] == 0) e[j]++, a /= sp[j];
		for(int j = 0; j < (int)sp.size(); j++) e[j] %= K;
		A[a].push_back(e);
	}
	cat ans = 0;
	for(int i = 0; i <= MX; i++) {
		if(i > 1 && K > 2) continue;
		static map<int, int> M;
		M.clear();
		for(auto & e : A[i]) {
			int x = 1, y = 1;
			for(int j = 0; j < (int)e.size(); j++) {
				for(int k = 0; k < e[j]; k++) x *= sp[j];
				for(int k = 0; k < (K-e[j])%K; k++) {
					y *= sp[j];
					y = min(y, MX+1);
				}
			}
			if(y <= MX) ans += M[y];
			M[x]++;
		}
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
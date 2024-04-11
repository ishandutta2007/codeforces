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
	int N[2];
	cin >> N[0] >> N[1];
	vector<int> P[2][2];
	for(int k = 0; k < 2; k++) {
		P[k][0].resize(N[k]);
		P[k][1].resize(N[k]);
		for(int i = 0; i < N[k]; i++) cin >> P[k][0][i] >> P[k][1][i];
	}
	int a[2];
	int ans = -1, ans_cnt = 0;
	bool know = true;
	for(int sh = 1; sh <= 9; sh++)
		for(a[0] = 1; a[0] <= 9; a[0]++) for(a[1] = 1; a[1] <= 9; a[1]++)
			if(sh != a[0] && sh != a[1] && a[0] != a[1]) {
				bool ok = false;
				for(int i = 0; i < N[0]; i++) {
					if(P[0][0][i] == sh && P[0][1][i] == a[0]) ok = true;
					if(P[0][1][i] == sh && P[0][0][i] == a[0]) ok = true;
				}
				if(!ok) continue;
				ok = false;
				for(int i = 0; i < N[1]; i++) {
					if(P[1][0][i] == sh && P[1][1][i] == a[1]) ok = true;
					if(P[1][1][i] == sh && P[1][0][i] == a[1]) ok = true;
				}
				if(!ok) continue;
				if(ans == -1) ans = sh;
				else if(ans != sh) ans_cnt++;
				// do both know the shared number?
				bool know_cur = true;
				for(int k = 0; k < 2; k++)
					// can a[k] be shared?
					// is there a pair containing a[k] and not sh?
					for(int i = 0; i < N[1-k]; i++)
						if(P[1-k][0][i] == a[k] || P[1-k][1][i] == a[k])
							if(P[1-k][0][i] != sh && P[1-k][1][i] != sh)
								know_cur = false;
				if(!know_cur) know = false;
			}
	if(ans_cnt == 0 && ans != -1) {
		cout << ans << "\n";
		return 0;
	}
	if(know) cout << "0\n";
	else cout << "-1\n";
	return 0;}

// look at my code
// my code is amazing
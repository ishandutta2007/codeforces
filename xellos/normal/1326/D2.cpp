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
	int T;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		int N = S.length();
		int l = 0, r = N-1;
		while(l < r && S[l] == S[r]) l++, r--;
		string Sp = S.substr(0, l);
		S = S.substr(l, r+1-l);
		string Si = S;
		reverse(begin(Si), end(Si));
		int L = S.length();
		cat mod[] = {1000000007, 1000000009};
		cat p = 999983;
		vector<cat> H[2], Hi[2], pp[2];
		for(int k = 0; k < 2; k++) {
			H[k].resize(L+1, 0);
			for(int i = 0; i < L; i++) H[k][i+1] = (H[k][i] * p + S[i]-'0'+1) % mod[k];
			Hi[k].resize(L+1, 0);
			for(int i = 0; i < L; i++) Hi[k][i+1] = (Hi[k][i] * p + Si[i]-'0'+1) % mod[k];
			pp[k].resize(L+1, 1);
			for(int i = 0; i < L; i++) pp[k][i+1] = pp[k][i] * p % mod[k];
		}
		for(int i = L; i >= 0; i--) {
			bool ok = true;
			for(int k = 0; k < 2; k++)
				if((Hi[k][L] - Hi[k][L-i] * pp[k][i] - H[k][i]) % mod[k] != 0)
					ok = false;
			if(ok) {
				string ans = Sp;
				ans += S.substr(0, i);
				reverse(begin(Sp), end(Sp));
				ans += Sp;
				cout << ans << "\n";
				break;
			}
			ok = true;
			for(int k = 0; k < 2; k++)
				if((H[k][L] - H[k][L-i] * pp[k][i] - Hi[k][i]) % mod[k] != 0)
					ok = false;
			if(ok) {
				string ans = Sp;
				ans += Si.substr(0, i);
				reverse(begin(Sp), end(Sp));
				ans += Sp;
				cout << ans << "\n";
				break;
			}
		}
	}
	return 0;
}

// look at my code
// my code is amazing
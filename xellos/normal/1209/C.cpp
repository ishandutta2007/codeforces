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
		int N;
		string S;
		cin >> N >> S;
		bool inc = true;
		for(int i = 0; i < N-1; i++) if(S[i+1] < S[i]) inc = false;
		if(inc) {
			string ans;
			for(int i = 0; i < N; i++) ans += '1';
			cout << ans << "\n";
			continue;
		}
		bool has_ans = false;
		for(int k = 0; k <= 9; k++) {
			bool ok = true;
			vector<char> C(N, 2);
			for(int i = 0; i < N; i++) if(S[i]-'0' > k) C[i] = 1;
			for(int i = 0; i < N; i++) if(S[i]-'0' < k) C[i] = 0;
			for(int i = 0; i < N; i++) if(S[i]-'0' > k) {
				for(int j = i+1; j < N; j++) if(S[j]-'0' == k) C[j] = 0;
				break;
			}
			for(int i = N-1; i >= 0; i--) if(S[i]-'0' < k) {
				for(int j = i-1; j >= 0; j--) if(S[j]-'0' == k) {
					if(C[j] != 2) ok = false;
					C[j] = 1;
				}
				break;
			}
			if(!ok) continue;
			// 2: only >= k after, only <= k before, consecutive
			char last = '0';
			for(int i = 0; i < N; i++) if(C[i] == 0) {
				if(last > S[i]) ok = false;
				last = S[i];
			}
			last = '0';
			for(int i = 0; i < N; i++) if(C[i] == 1) {
				if(last > S[i]) ok = false;
				last = S[i];
			}
			if(!ok) continue;
			has_ans = true;
			string ans;
			for(int i = 0; i < N; i++) {
				if(C[i] == 1) ans += '2';
				else ans += '1';
			}
			cout << ans << "\n";
			break;
		}
		if(!has_ans) cout << "-\n";
	}
	return 0;
}

// look at my code
// my code is amazing
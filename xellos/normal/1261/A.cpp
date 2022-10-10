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
		int N, K;
		string S;
		cin >> N >> K >> S;
		int cur = 0;
		vector< pair<int, int> > ans;
		while(K > 1) {
			for(int i = cur; i < N; i++) if(S[i] == '(') {
				ans.push_back({cur, i});
				reverse(begin(S)+cur, begin(S)+i+1);
				break;
			}
			cur++;
			for(int i = cur; i < N; i++) if(S[i] == ')') {
				ans.push_back({cur, i});
				reverse(begin(S)+cur, begin(S)+i+1);
				break;
			}
			cur++;
			K--;
		}
		K = (N-cur)/2;
		while(K) {
			for(int i = cur; i < N; i++) if(S[i] == '(') {
				ans.push_back({cur, i});
				reverse(begin(S)+cur, begin(S)+i+1);
				break;
			}
			cur++;
			K--;
		}
		cout << ans.size() << "\n";
		for(auto p : ans) cout << p.ff+1 << " " << p.ss+1 << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
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

void reverse(auto & A, int L) {
	reverse(begin(A), begin(A)+L+1);
	for(int i = 0; i <= L; i++) if(A[i] == 1 || A[i] == 2) A[i] = 3 - A[i];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		string s[2];
		cin >> s[0] >> s[1];
		int N = s[0].length()/2;
		vector<int> A[2];
		int cnt[] = {0, 0, 0, 0};
		for(int k = 0; k < 2; k++) {
			A[k].resize(N);
			for(int i = 0; i < N; i++) {
				A[k][i] = (s[k][2*i]-'0')*2+(s[k][2*i+1]-'0');
				if(k == 0) cnt[A[k][i]]++;
				else cnt[A[k][i]]--;
			}
		}
		if(cnt[0] != 0 || cnt[3] != 0 || cnt[1]+cnt[2] != 0) {
			cout << "-1\n";
			continue;
		}
		vector<int> ans[2];
		while(N) {
			if(A[0][N-1] == A[1][N-1]) {
				N--;
				continue;
			}
			if(A[1][N-1] == 0 || A[1][N-1] == 3) {
				int p = N-1;
				while(A[0][p] != A[1][N-1]) p--;
				ans[0].push_back(2*(p+1));
				ans[0].push_back(2*N);
				reverse(A[0], p);
				reverse(A[0], N-1);
				N--;
				continue;
			}
			if(A[0][N-1] == 0 || A[0][N-1] == 3) {
				int p = N-1;
				while(A[1][p] != A[0][N-1]) p--;
				ans[1].push_back(2*(p+1));
				ans[1].push_back(2*N);
				reverse(A[1], p);
				reverse(A[1], N-1);
				N--;
				continue;
			}
			if(A[0][0] == 3-A[1][N-1]) {
				ans[0].push_back(2*N);
				reverse(A[0], N-1);
				N--;
				continue;
			}
			if(A[1][0] == 3-A[0][N-1]) {
				ans[1].push_back(2*N);
				reverse(A[1], N-1);
				N--;
				continue;
			}
			if(A[0][0] == A[1][0]) {
				ans[0].push_back(2*N);
				ans[1].push_back(2*N);
				reverse(A[0], N-1);
				reverse(A[1], N-1);
				N--;
				continue;
			}
			if(A[0][0] == A[1][N-1]) {
				ans[0].push_back(2);
				ans[0].push_back(2*N);
				reverse(A[0], 0);
				reverse(A[0], N-1);
				N--;
				continue;
			}
			if(A[1][0] == A[0][N-1]) {
				ans[1].push_back(2);
				ans[1].push_back(2*N);
				reverse(A[1], 0);
				reverse(A[1], N-1);
				N--;
				continue;
			}
			if(A[0][0] == 0 || A[0][0] == 3) {
				int p = 0;
				for(int i = 1; i < N; i++) if(A[0][i] == A[0][0] && A[0][i-1] != A[0][0]) {
					p = i;
					break;
				}
				if(p) {
					ans[0].push_back(2*p);
					reverse(A[0], p-1);
					continue;
				}
			}
			if(A[1][0] == 0 || A[1][0] == 3) {
				int p = 0;
				for(int i = 1; i < N; i++) if(A[1][i] == A[1][0] && A[1][i-1] != A[1][0]) {
					p = i;
					break;
				}
				if(p) {
					ans[1].push_back(2*p);
					reverse(A[1], p-1);
					continue;
				}
			}
			int p[2] = {0, 0};
			for(int k = 0; k < 2; k++) while(A[k][p[k]] == A[k][0]) p[k]++;
			ans[0].push_back(2*N);
			reverse(A[0], N-1);
		}
		reverse(begin(ans[1]), end(ans[1]));
		for(auto x : ans[1]) ans[0].push_back(x);
		cout << ans[0].size() << "\n";
		for(int i = 0; i < (int)ans[0].size(); i++)
			cout << ans[0][i] << ((i == ans[0].size()-1) ? "" : " ");
		cout << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
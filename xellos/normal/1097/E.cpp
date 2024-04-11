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

struct fin {
	vector<int> T;
	fin() {}
	fin(int N) {T.resize(N, 0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] = max(T[i], val);
	}

	void clear() {
		for(int i = 0; i < (int)T.size(); i++) T[i] = 0;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret = max(ret, T[i]);
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			A[i]--;
		}
		vector<bool> used(N, false);
		vector<int> L(N, 0);
		fin F(N+10);
		vector< vector<int> > ans;
		while(true) {
			int Lmax = 0, N_cur = 0;
			for(int i = 0; i < N; i++) if(!used[i]) {
				N_cur++;
				L[i] = 1 + F.get(A[i]-1);
				F.put(A[i], L[i]);
				Lmax = max(Lmax, L[i]);
			}
			if(N_cur == 0) break;
			F.clear();
			int n = 0, K = 0;
			while(n < N_cur) n += ++K;
			if(Lmax >= K) {
				vector<int> v;
				int cur = N+1;
				for(int i = N-1; i >= 0; i--) if(!used[i] && Lmax == L[i] && A[i] < cur) {
					v.push_back(A[i]);
					Lmax--;
					cur = A[i];
					used[i] = true;
				}
				reverse(begin(v), end(v));
				ans.push_back(v);
			}
			else {
				vector< vector<int> > seq(Lmax+1);
				for(int i = 0; i < N; i++) if(!used[i]) seq[L[i]].push_back(A[i]);
				for(int i = 1; i <= Lmax; i++) ans.push_back(seq[i]);
				break;
			}
		}
		cout << ans.size() << "\n";
		ALL_THE(ans, it) {
			vector<int> v = *it;
			cout << v.size() << " ";
			for(int i = 0; i < (int)v.size(); i++) cout << v[i]+1 << ((i == (int)v.size()-1) ? "\n" : " ");
		}
	}
	return 0;
}

// look at my code
// my code is amazing
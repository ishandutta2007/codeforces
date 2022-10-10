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

struct itree {
	int b;
	vector<char> T, U;

	itree(int N) : b(1) {
		while(b < N) b *= 2;
		T.resize(2*b+10, 0);
		U.resize(2*b+10, 0);
	}

	void put(int Il, int Ir, int l = 0, int r = 0, int cur = 1) {
		if(cur == 1) r = b;
		Il = max(Il, l);
		Ir = min(Ir, r);
		if(Il >= r || l >= Ir) return;
		if(Il == l && Ir == r) {
			T[cur] = U[cur] = 1;
			return;
		}
		put(Il, Ir, l, (l+r)/2, 2*cur);
		put(Il, Ir, (l+r)/2, r, 2*cur+1);
		if(T[2*cur] || T[2*cur+1]) T[cur] = 1;
	}

	char get(int Il, int Ir, int l = 0, int r = 0, int cur = 1) {
		if(cur == 1) r = b;
		Il = max(Il, l);
		Ir = min(Ir, r);
		if(Il >= r || l >= Ir) return 0;
		if(U[cur]) return 1;
		if(Il == l && Ir == r) return T[cur];
		if(get(Il, Ir, l, (l+r)/2, 2*cur)) return 1;
		return get(Il, Ir, (l+r)/2, r, 2*cur+1);
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> sa(N), ea(N), sb(N), eb(N);
	map<int, int> M;
	for(int i = 0; i < N; i++) {
		cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
		M[sa[i]] = M[ea[i]+1] = M[sb[i]] = M[eb[i]+1] = 0;
	}
	int m = 0;
	for(auto & p : M) p.ss = m++;
	{
		vector< pair<int, int> > Es(N);
		for(int i = 0; i < N; i++) Es[i] = {ea[i], i};
		sort(begin(Es), end(Es));
		vector< pair<int, int> > Ss(N);
		for(int i = 0; i < N; i++) Ss[i] = {sa[i], i};
		sort(begin(Ss), end(Ss));
		itree I(m+10);
		for(int i = 0, j = 0; i < N; i++) {
			while(j < N && Es[j].ff < Ss[i].ff) {
				I.put(M[sb[Es[j].ss]], M[eb[Es[j].ss]+1]);
				j++;
			}
			if(I.get(M[sb[Ss[i].ss]], M[eb[Ss[i].ss]+1])) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	{
		vector< pair<int, int> > Es(N);
		for(int i = 0; i < N; i++) Es[i] = {eb[i], i};
		sort(begin(Es), end(Es));
		vector< pair<int, int> > Ss(N);
		for(int i = 0; i < N; i++) Ss[i] = {sb[i], i};
		sort(begin(Ss), end(Ss));
		itree I(m+10);
		for(int i = 0, j = 0; i < N; i++) {
			while(j < N && Es[j].ff < Ss[i].ff) {
				I.put(M[sa[Es[j].ss]], M[ea[Es[j].ss]+1]);
				j++;
			}
			if(I.get(M[sa[Ss[i].ss]], M[ea[Ss[i].ss]+1])) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}

// look at my code
// my code is amazing
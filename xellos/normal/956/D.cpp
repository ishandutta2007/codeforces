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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct plane {
	cat x, v, w;
	int id;

	bool operator<(const plane &P) const {
		if((x > 0) == (P.x > 0))
			return (v+w)*P.x < x*(P.v+P.w);
		return (v+w)*P.x > x*(P.v+P.w);
	}

	bool operator==(const plane &P) const {
		return (v+w)*P.x == x*(P.v+P.w);
	}
};

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+10, 0);}

	int lastone(int x) {
		return x&(x^(x-1));
	}

	void put(int pos) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i]++;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, W;
	cin >> N >> W;
	vector<plane> Pp(N), Pn(N);
	for(int i = 0; i < N; i++) {
		cin >> Pp[i].x >> Pp[i].v;
		Pp[i].id = i;
		Pn[i] = Pp[i];
		Pp[i].w = W, Pn[i].w = -W;
	}
	sort(begin(Pp), end(Pp));
	sort(begin(Pn), end(Pn));
	vector<int> posn(N), posp(N);
	for(int i = 0; i < N; i++) {
		int j = i;
		while(j < N && Pp[j] == Pp[i]) j++;
		for(int k = i; k < j; k++) posp[Pp[k].id] = N-1-i;
		i = j-1;
	}
	for(int i = 0; i < N; i++) {
		int j = i;
		while(j < N && Pn[j] == Pn[i]) j++;
		for(int k = i; k < j; k++) posn[Pn[k].id] = N-1-i;
		i = j-1;
	}
	cat ans = 0;

	if(W == 0) {
		for(int i = 0; i < N; i++) {
			int j = i;
			while(j < N && Pp[j] == Pp[i]) j++;
			ans += 1LL*(j-i)*(j-i-1)/2;
			i = j-1;
		}
		cout << ans << "\n";
		return 0;
	}

	fin F(N), Fid(N);
	for(int i = 0; i < N; i++) {
		int j = i;
		while(j < N && Pp[j] == Pp[i]) j++;
		ans += 1LL*(j-i)*(j-i-1);
		for(int k = i; k < j; k++)
			ans += F.get(posn[Pp[k].id]-1);
		for(int k = i; k < j; k++)
			F.put(posn[Pp[k].id]);
		i = j-1;
	}
	F = fin(N);
	for(int i = 0; i < N; i++) {
		int j = i;
		while(j < N && Pn[j] == Pn[i]) j++;
		ans += 1LL*(j-i)*(j-i-1);
		for(int k = i; k < j; k++)
			ans += F.get(posp[Pn[k].id]-1);
		for(int k = i; k < j; k++)
			F.put(posp[Pn[k].id]);
		i = j-1;
	}
	cout << ans/2 << "\n";
	return 0;}

// look at my code
// my code is amazing
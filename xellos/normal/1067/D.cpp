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

bool cmp(cat a, cat b, cat c, cat d) {
	// true if a*b > c*d
	cat ah = a>>30, al = a&((1<<30)-1);
	cat bh = b>>30, bl = b&((1<<30)-1);
	cat ch = c>>30, cl = c&((1<<30)-1);
	cat dh = d>>30, dl = d&((1<<30)-1);
	// a*b = (ah*bh)<<60 + (ah*bl+al*bh)<<30 + al*bl
	cat dif = ah*bh-ch*dh;
	if(dif >= (1LL<<31)) return true;
	if(dif <= -(1LL<<31)) return false;
	dif = dif * (1<<30) + ah*bl+al*bh-ch*dl-cl*dh;
	if(dif >= (1LL<<30)) return true;
	if(dif <= -(1LL<<30)) return false;
	dif = dif * (1<<30) + al*bl-cl*dl;
	return (dif > 0);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat T;
	cin >> N >> T;
	cat M = 0;
	vector< pair<cat, cat> > V(N);
	for(int i = 0; i < N; i++) {
		int a, b;
		double p;
		cin >> a >> b >> p;
		int p_i = p*1e9+.01;
		V[i] = {p_i, 1LL*a*p_i};
		M = max(M, 1LL*b*p_i);
	}
	sort(begin(V), end(V));

	// hull
	int a = N-1;
	for(int i = N-1, mx = -1; i >= 0; i--) if(V[i].ss > mx) {
		mx = V[i].ss;
		V[a] = V[i];
		a--;
	}
	for(int i = a+1; i < N; i++) V[i-a-1] = V[i];
	V.resize(N-1-a);
	N -= a+1;
	a = (N == 1) ? 0 : 1;
	for(int i = 2; i < N; i++) {
		while(a > 0) {
			if(cmp(V[a].ss-V[i].ss, V[a].ff-V[a-1].ff, V[a-1].ss-V[a].ss, V[i].ff-V[a].ff)) break;
			a--;
		}
		V[a+1] = V[i];
		a++;
	}
	V.resize(a+1);
	N = a+1;

	double E = 0;
	a = 0;
	for(cat k = 0; k < T; k++) {
		cat n = T-k;
		double c = 1. * (M - V[a].ss) / V[a].ff;
		double d = 1.*k*M/1e9 - E;
		double p = 1. - V[a].ff/1e9;
		if(a < N-1) {
			double crit = 1.*(V[a].ss-V[a+1].ss) / (V[a+1].ff-V[a].ff);
			if(c-d <= 0) return 1;
			if(d > crit) n = 0;
			if(c-crit > 0 && d <= crit) {
				n = floor((log(c-d)-log(c-crit)) / (-log(p)));
				n = max(n, 0LL);
				n = min(n, T-k);
			}
		}
		k += n;
		E = 1.*k*M/1e9 - d * pow(p, n) - c * (1 - pow(p, n));
		if(k == T) break;
		double E_new = (V[a].ff / 1e9) * (k * (M / 1e9) - E) + (E + V[a].ss / 1e9);
		int a_new = a;
		for(int i = a+1; i < N; i++) {
			double val = (V[i].ff / 1e9) * (k * (M / 1e9) - E) + (E + V[i].ss / 1e9);
			if(val > E_new - soclose) {
				E_new = val;
				a_new = i;
			}
			else if(val < E_new - soclose)
				break;
		}
		E = E_new;
		a = a_new;
	}
	cout << E << "\n";
	return 0;
}

// look at my code
// my code is amazing
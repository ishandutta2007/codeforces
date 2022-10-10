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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	return (a == 0) ? b : gcd(b%a, a);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cat> A(N);
	set<cat> G; // all GCDs
	map<cat, int> fact;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		for(int e = 5; e >= 2; e--) {
			cat c = pow(A[i], 1./e), pw;
			while(c > 0) {
				pw = c;
				for(int j = 0; j < e-1; j++) pw = pw * c;
				if(pw > A[i]) c--;
				else break;
			}
			while(true) {
				pw = c;
				for(int j = 0; j < e-1; j++) pw = pw * c;
				if(pw < A[i]) c++;
				else break;
			}
			if(pw == A[i]) {
				fact[c] += e;
				A[i] = 1;
				G.insert(c);
				break;
			}
		}
		if(A[i] > 1) for(int j = 0; j < i; j++) if(A[j] > 1) {
			cat g = gcd(A[i], A[j]);
			if(g > 1 && g != A[i]) G.insert(g); // A[i] != A[j]
		}
	}
	set<cat> G_proc;
	while(!G.empty()) {
		cat g = *begin(G);
		G_proc.insert(g);
		G.erase(begin(G));
		int e = 0;
		for(int i = 0; i < N; i++) if(A[i]%g == 0) {
			e++;
			A[i] /= g;
			if(A[i] > 1 && G_proc.count(A[i]) == 0) G.insert(A[i]);
		}
		fact[g] += e;
	}
	cat ans = 1, mod = 998244353;
	ALL_THE(fact, it) ans = ans * (it->ss+1) % mod;
	map<cat, int> prod_occ; // occurrences of A[i] == p*q
	for(int i = 0; i < N; i++) if(A[i] > 1) prod_occ[A[i]]++;
	ALL_THE(prod_occ, it) ans = ans * (it->ss+1) * (it->ss+1) % mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
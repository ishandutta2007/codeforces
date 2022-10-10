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

void sub(int pos, vector<int> & occ, vector<int> & occT, int & dif) {
	dif -= abs(occ[pos]-occT[pos]);
	occ[pos]--;
	dif += abs(occ[pos]-occT[pos]);
}

void add(int pos, vector<int> & occ, vector<int> & occT, int & dif) {
	dif -= abs(occ[pos]-occT[pos]);
	occ[pos]++;
	dif += abs(occ[pos]-occT[pos]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	unsigned K;
	cin >> K;
	int N = 1<<K;
	vector<int> A(N), occT(N, 0);
	int x = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		x ^= A[i];
		occT[A[i]]++;
	}

	srand(std::chrono::steady_clock::now().time_since_epoch().count());

	if(x != 0) {
		cout << "Fou\n";
		return 0;
	}
	
	vector<int> P(N), occ(N, 1);
	for(int i = 0; i < (1<<(K-1)); i++) {
		P[2*i] = i;
		P[N-1-2*i] = (1<<(K-1))+i;
	}
	if(K%2 != 0)
		for(int i = 0; i < (1<<(K-2)); i++) swap(P[N/2+2*i], P[N/2+2*i+1]);

	int dif = 0;
	for(int i = 0; i < N; i++) {
		dif += abs(occT[i]-occ[i]);
	}

	int step;
	for(step = 0; ; step++) {
		// cerr << dif << "\n";
		if(dif == 0) break;

		vector<int> p(N);
		for(int i = 0; i < N; i++) {
			p[i] = i;
			swap(p[i], p[rand()%(i+1)]);
		}

		bool fail = true;
		for(int k = 0; k < 2; k++) if(k == 0 || fail)
		for(int i = 0; i < N; i++) if(occ[p[i]^P[p[i]]] > occT[p[i]^P[p[i]]]) for(int j = 0; j < i; j++) {
			int dif_nw = dif;
			sub(p[i] ^ P[p[i]], occ, occT, dif_nw);
			sub(p[j] ^ P[p[j]], occ, occT, dif_nw);
			add(p[i] ^ P[p[j]], occ, occT, dif_nw);
			add(p[j] ^ P[p[i]], occ, occT, dif_nw);
			if(dif_nw < dif || (dif_nw <= dif && fail)) {
				swap(P[p[i]], P[p[j]]);
				dif = dif_nw;
				if(k == 0) fail = false;
				continue;
			}
			occ[p[i] ^ P[p[i]]]++;
			occ[p[j] ^ P[p[j]]]++;
			occ[p[i] ^ P[p[j]]]--;
			occ[p[j] ^ P[p[i]]]--;
		}
	}
	// cerr << step << " " << dif << "\n";
	// return 0;
	cout << "Shi\n";
	vector< pair<int, int> > ans(N);
	for(int i = 0; i < N; i++) ans[i] = {i, P[i]};
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++) if((ans[j].ff ^ ans[j].ss) == A[i]) {
			swap(ans[i], ans[j]);
			break;
		}
	for(int i = 0; i < N; i++) cout << ans[i].ff << ((i == N-1) ? "\n" : " ");
	for(int i = 0; i < N; i++) cout << ans[i].ss << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
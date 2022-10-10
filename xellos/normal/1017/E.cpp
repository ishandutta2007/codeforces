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

struct pt {
	cat x, y;

	bool operator<(const pt & P) const {
		if(x != P.x) return x < P.x;
		return y < P.y;
	}
};

cat ss(pt & A, pt & B) {
	return (A.x-B.x) * (A.x-B.x) + (A.y-B.y) * (A.y-B.y);
}

cat vs(pt & A, pt & B, pt & O) {
	return (A.x-O.x) * (B.y-O.y) - (B.x-O.x) * (A.y-O.y);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N[2];
	cin >> N[0] >> N[1];
	vector<pt> P[2];
	vector<int> H[2];
	vector<cat> V[2];
	for(int k = 0; k < 2; k++) {
		P[k].resize(N[k]);
		for(int i = 0; i < N[k]; i++) cin >> P[k][i].x >> P[k][i].y;
		sort(begin(P[k]), end(P[k]));
		H[0] = H[1] = vector<int>(1, 0);
		for(int i = 0; i < N[k]; i++) {
			if(vs(P[k][i], P[k][N[k]-1], P[k][0]) >= 0) {
				while((int)H[0].size() > 1 && vs(P[k][i], P[k][H[0][H[0].size()-1]], P[k][H[0][H[0].size()-2]]) >= 0) H[0].pop_back();
				H[0].push_back(i);
			}
			if(vs(P[k][i], P[k][N[k]-1], P[k][0]) <= 0) {
				while((int)H[1].size() > 1 && vs(P[k][i], P[k][H[1][H[1].size()-1]], P[k][H[1][H[1].size()-2]]) <= 0) H[1].pop_back();
				H[1].push_back(i);
			}
		}
		vector<int> Hr = H[0];
		reverse(begin(Hr), end(Hr));
		for(int i = 1; i < (int)H[1].size()-1; i++) Hr.push_back(H[1][i]);
		vector<cat> V1(2*Hr.size());
		for(int i = 0; i < (int)Hr.size(); i++) {
			V1[2*i] = ss(P[k][Hr[i]], P[k][Hr[(i+1)%Hr.size()]]);
			V1[2*i+1] = ss(P[k][Hr[i]], P[k][Hr[(i+2)%Hr.size()]]);
		}
		vector<cat> V2 = V1;
		int sz = V1.size();
		for(int i = 0; i < sz; i++) V2.push_back(V1[i]);
		cat mod[2] = {1000000007, 1000000009};
		cat p = 999983;
		cat pw[2] = {1, 1};
		vector<cat> hash(sz);
		cat hc[2] = {0, 0};
		for(int j = 0; j < 2; j++) for(int i = 0; i < sz; i++) pw[j] = pw[j] * p % mod[j];
		for(int j = 0; j < 2; j++) for(int i = 0; i < sz; i++) hc[j] = (hc[j] * p + V2[i] % mod[j]) % mod[j];
		for(int i = 0; i < sz; i++) {
			hash[i] = hc[0] * mod[1] + hc[1];
			for(int j = 0; j < 2; j++) {
				hc[j] = (hc[j] * p + V2[sz+i] - V2[i] % mod[j] * pw[j]) % mod[j];
				if(hc[j] < 0) hc[j] += mod[j];
			}
		}
		sort(begin(hash), end(hash));
		V[k] = hash;
	}
	if(V[0].size() != V[1].size()) {
		cout << "NO\n";
		return 0;
	}
	for(int i = 0; i < (int)V[0].size(); i++) if(V[0][i] != V[1][i]) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}

// look at my code
// my code is amazing
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

constexpr int B = 64;
constexpr uint64_t b1 = 1;

void solve() {
	int N, M;
	cin >> N >> M;
	vector< vector<uint64_t> > bits(N, vector<uint64_t>(M/B+1, 0));
	for(int i = 0; i < M; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < N; j++) if(s[j] == '1') bits[j][i/B] |= b1<<(i%B);
	}
	vector<int> par(N, -1);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(i != j && par[j] == -1) {
		bool sub = true;
		for(int k = 0; k <= M/B; k++) {
			uint64_t b = bits[i][k] & bits[j][k];
			if(b != bits[i][k]) {
				sub = false;
				break;
			}
		}
		if(sub) {
			par[i] = j;
			break;
		}
	}

	vector<int> occ(M, 0);
	for(int j = 0; j < N; j++) if(par[j] == -1)
		for(int i = 0; i < M; i++) occ[i] += (bits[j][i/B]>>(i%B))&1;
	vector<uint64_t> bits_one(M/B+1, 0);
	queue<int> q;
	for(int i = 0; i < M; i++) {
		if(occ[i] == 1) q.push(i);
		if(occ[i] <= 1) bits_one[i/B] |= b1<<(i%B);
	}
	while(!q.empty()) {
		int c = q.front(), id_one = -1;
		for(int i = 0; i < N; i++) if(par[i] == -1)
			if((bits[i][c/B]>>(c%B))&1) id_one = i;
		if(id_one == -1) {
			q.pop();
			continue;
		}
		int p = -1;
		for(int i = 0; i < N; i++) if(par[i] == -1 && i != id_one) {
			bool ok = true;
			for(int j = 0; j <= M/B; j++) {
				uint64_t b = bits[i][j] | bits_one[j];
				if((b & bits[id_one][j]) != bits[id_one][j]) {
					ok = false;
					break;
				}
			}
			if(ok) {
				p = i;
				break;
			}
		}
		if(p != -1) {
			par[id_one] = p;
			for(int i = 0; i < M; i++) if((bits[id_one][i/B]>>(i%B))&1) {
				occ[i]--;
				if(occ[i] == 1) {
					bits_one[i/B] |= b1<<(i%B);
					q.push(i);
				}
			}
		}
		q.pop();
	}

	int cnt_R = 0;
	for(int i = 0; i < N; i++) if(par[i] == -1) cnt_R++;
	if(cnt_R > 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 0; i < N; i++) if(par[i] != -1)
		cout << i+1 << " " << par[i]+1 << "\n";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}

// look at my code
// my code is amazing
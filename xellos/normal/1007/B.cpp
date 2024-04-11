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
	int MX = 100000;
	vector<int> div(MX+10, 1);
	for(int i = 2; i <= MX; i++) if(div[i] == 1) {
		div[i] = i;
		for(int j = i; j <= MX/i; j++) div[i*j] = i;
	}
	vector< vector<int> > divs_mem(MX+10);
	int T;
	cin >> T;
	vector<int> occ[3];
	for(int i = 0; i < 3; i++) occ[i].resize(MX+10, 0);
	vector<uint8_t> id_select[3][3][8];
	for(int b0 = 1; b0 < 8; b0++)
		for(int b1 = 1; b1 < 8; b1++)
			for(int b2 = 1; b2 < 8; b2++) {
				vector<int> canon_order;
				for(int id0 = 0; id0 < 3; id0++)
					for(int id1 = 0; id1 < 3; id1++) if(id0 != id1)
						if((b0>>id0)&1) if((b1>>id1)&1) if((b2>>(3-id0-id1))&1)
							canon_order = {id0, id1, 3-id0-id1};
				if(canon_order.empty()) continue;
				id_select[canon_order[1]][canon_order[0]][b1].push_back((b0<<3)+b2);
			}
	vector<int> bitmask(MX+10, 0);
	while(T--) {
		int A[3];
		cin >> A[0] >> A[1] >> A[2];
		vector<int> divs[3];
		for(int i = 0; i < 3; i++) {
			if(!divs_mem[A[i]].empty()) {
				divs[i] = divs_mem[A[i]];
				continue;
			}
			int a = A[i];
			divs[i] = {1};
			while(a > 1) {
				int p = div[a], e = 0;
				while(a % p == 0) {
					a /= p;
					e++;
				}
				int ppw = 1, sz = divs[i].size();
				divs[i].resize(sz * (e+1));
				for(int j = 0; j < e; j++) {
					ppw *= p;
					for(int k = 0; k < sz; k++) divs[i][sz * (j+1) + k] = divs[i][k] * ppw;
				}
			}
			sort(begin(divs[i]), end(divs[i]));
			divs_mem[A[i]] = divs[i];
		}
		for(int i = 0; i < 3; i++) ALL_THE(divs[i], it) {
			occ[i][*it] = 1;
			bitmask[*it] |= 1<<i;
		}
		int D[3] = {};
		for(int i = 0; i < 3; i++) D[i] = divs[i].size();
		bool used[3][8] = {};
		for(int i = 0; i < 3; i++) for(int j = 0; j < D[i]; j++)
			used[i][bitmask[divs[i][j]]] = 1;
		int ans = 0;
		int ord[3];
		for(ord[1] = 0; ord[1] < 3; ord[1]++)
			for(ord[0] = 0; ord[0] < 3; ord[0]++) if(ord[1] != ord[0]) {
				ord[2] = 3-ord[0]-ord[1];
				int lt[8] = {}, gt[8] = {};
				bool is_used[8] = {};
				for(int i = 1; i < 8; i++) if(used[ord[1]][i]) ALL_THE(id_select[ord[1]][ord[0]][i], it)
					if(used[ord[0]][*it>>3] && used[ord[2]][*it&7]) is_used[i] = true;
				for(int i = 0; i < D[ord[2]]; i++) gt[bitmask[divs[ord[2]][i]]]++;
				int a = 0, b = 0;
				vector<int> & d_lt = divs[ord[0]];
				vector<int> & d_gt = divs[ord[2]];
				for(int i = 0; i < D[ord[1]]; i++) {
					int x = divs[ord[1]][i];
					if(!is_used[bitmask[x]]) continue;
					while(a < D[ord[0]] && d_lt[a] <= x) {
						lt[bitmask[d_lt[a]]]++;
						a++;
					}
					while(b < D[ord[2]] && d_gt[b] < x) {
						gt[bitmask[d_gt[b]]]--;
						b++;
					}
					vector<uint8_t> & v = id_select[ord[1]][ord[0]][bitmask[x]];
					for(int j = 0; j < (int)v.size(); j++)
						ans += lt[v[j]>>3] * gt[v[j]&7];
				}
			}
		cout << ans << "\n";
		for(int i = 0; i < 3; i++) ALL_THE(divs[i], it)
			occ[i][*it] = bitmask[*it] = 0;
	}
	return 0;
}

// look at my code
// my code is amazing
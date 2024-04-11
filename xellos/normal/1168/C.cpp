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
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector< vector<int> > min_nxt[19];
	for(int i = 0; i < 19; i++) {
		min_nxt[i].resize(i, vector<int>(N+1, N));
		for(int j = 0; j < N; j++) if((A[j]>>i)&1)
			for(int k = 0; k < i; k++) if((A[j]>>k)&1) min_nxt[i][k][j] = j;
		for(int j = 0; j < i; j++) for(int k = N-1; k >= 0; k--)
			min_nxt[i][j][k] = min(min_nxt[i][j][k], min_nxt[i][j][k+1]);
	}
	for(int q = 0; q < Q; q++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if(A[x] == 0 || A[y] == 0) {
			cout << "Fou\n";
			continue;
		}
		if(A[x] & A[y]) {
			cout << "Shi\n";
			continue;
		}
		priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > bits;
		vector<int> bit_pos(19, y+1);
		for(int i = 0; i < 19; i++) if((A[x]>>i)&1) {
			bit_pos[i] = x;
			bits.push({x, i});
		}
		bool br = false;
		while(!bits.empty()) {
			int pos = bits.top().ff, b = bits.top().ss;
			bits.pop();
			if(pos != bit_pos[b]) continue;
			for(int j = 0; j < b; j++) if(((A[pos]>>j)&1) == 0)
				if(bit_pos[j] > pos && min_nxt[b][j][pos] < bit_pos[j]) {
					bit_pos[j] = min_nxt[b][j][pos];
					if(A[y] & A[bit_pos[j]]) br = true;
					bits.push({bit_pos[j], j});
				}
			for(int j = b+1; j < 19; j++) if(((A[pos]>>j)&1) == 0)
				if(bit_pos[j] > pos && min_nxt[j][b][pos] < bit_pos[j]) {
					bit_pos[j] = min_nxt[j][b][pos];
					if(A[y] & A[bit_pos[j]]) br = true;
					bits.push({bit_pos[j], j});
				}
			if(br) break;
		}
		cout << (br ? "Shi\n" : "Fou\n");
	}
	return 0;
}

// look at my code
// my code is amazing
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

int get_K(int size) {
	return size/2-1;
}

int get_N(int size) {
	int K = get_K(size);
	int N = 2*(size-K)+size;
	if(K <= size/2) N--;
	if(size-K-1 >= size/2) N--;
	return N;
}

int get_size(int N) {
	int size = 0;
	while(get_N(size+1) <= N) size++;
	return size;
}

vector< vector<char> > build(int size) {
	int K = get_K(size);
	vector< vector<char> > tbl(size, vector<char>(size, 0));
	for(int i = K; i < size; i++) tbl[size/2][i] = 1;
	for(int i = 0; i < size-K; i++) tbl[size/2+1][i] = 1;
	for(int i = 0; i < size; i++) tbl[i][size/2] = 1;
	return tbl;
}

vector< vector<char> > simulate(vector< vector<char> > tbl) {
	int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
	int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
	int size = tbl.size();
	while(true) {
		bool br = true;
		for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) {
			if(tbl[i][j]) continue;
			int cnt = 0;
			for(int k = 0; k < 8; k++) {
				int x = i-dx[k], y = j-dy[k];
				if(x < 0 || y < 0 || x >= size || y >= size) continue;
				cnt += tbl[x][y];
			}
			if(cnt >= 4) tbl[i][j] = 1, br = false;
		}
		if(br) break;
	}
	return tbl;
}

void check(vector< vector<char> > & tbl, int N) {
	int size = tbl.size();
	vector< vector<char> > res = simulate(tbl);
	int final = 0;
	for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) {
		if(res[i][j]) final++;
	}
	cerr << N << " " << final << " " << N*N/10 << "\n";
	assert(final >= N*N/10);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	if(N <= 10) {
		for(int i = 0; i < N; i++) cout << "0 " << i << "\n";
		return 0;
	}
	if(N <= 22) {
		for(int i = 0; i < N/2; i++) cout << "0 " << i << "\n";
		for(int i = 0; i < N-N/2; i++) cout << "3 " << i << "\n";
		return 0;
	}
	int size = get_size(N);
	vector< vector<char> > tbl = build(size);
	vector< pair<int, int> > ans;
	for(int i = 0; i < size; i++) for(int j = 0; j < size; j++)
		if(tbl[i][j]) ans.push_back({i, j});
	while((int)ans.size() < N) ans.push_back({-1, ans.size()});
	ALL_THE(ans, it) cout << it->ff << " " << it->ss << "\n";
	// check(tbl, N);
	return 0;
}

// look at my code
// my code is amazing
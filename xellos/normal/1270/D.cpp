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
	int N, K;
	cin >> N >> K;
	vector<int> A(N, -1);
	for(int i = 0; i <= N-K; i++) {
		cout << "?";
		vector<int> ids;
		for(int j = 0; j < N; j++) if((int)ids.size() < K && A[j] == -1) {
			ids.push_back(j);
			cout << " " << j+1;
		}
		cout << endl;
		int pos, a;
		cin >> pos >> a;
		A[pos-1] = a;
	}
	vector<int> good_ids;
	vector<int> bad_ids;
	for(int i = 0; i < N; i++) {
		if(A[i] >= 0) good_ids.push_back(i);
		else bad_ids.push_back(i);
	}
	if(K == 1) {
		cout << "! 1" << endl;
		return 0;
	}
	if(N-K+1 >= K) {
		cout << "?";
		for(int i = 0; i < K; i++) cout << " " << good_ids[i]+1;
		cout << endl;
		int pos, a;
		cin >> pos >> a;
		int M = 1;
		for(int i = 0; i < K; i++) if(A[good_ids[i]] < a) M++;
		cout << "! " << M << endl;
		return 0;
	}
	else {
		vector<int> id_st = good_ids;
		for(int i = 0; i < K-(N-K+1); i++) id_st.push_back(bad_ids[i]); // 0, i
		cout << "?";
		for(int i = 0; i < K; i++) cout << " " << id_st[i]+1;
		cout << endl;
		int pos_st, a_st;
		cin >> pos_st >> a_st;
		bool flip_gr = false;
		vector<bool> g(K-1, 0);
		for(int i = K-(N-K+1); i < K-1; i++) {
			vector<int> ids = id_st;
			for(int j = 0; j < K; j++) if(ids[j] == bad_ids[0]) {
				ids[j] = bad_ids[i];
				break;
			}
			cout << "?";
			for(int j = 0; j < K; j++) cout << " " << ids[j]+1;
			cout << endl;
			int pos, a;
			cin >> pos >> a;
			if(pos != pos_st) {
				if(a < a_st) flip_gr = true;
				g[i] = 1;
			}
		}
		for(int i = 1; i < K-(N-K+1); i++) {
			vector<int> ids = id_st; // 0, K-2
			for(int j = 0; j < K; j++) if(ids[j] == bad_ids[i]) {
				ids[j] = bad_ids[K-2];
				break;
			}
			cout << "?";
			for(int j = 0; j < K; j++) cout << " " << ids[j]+1;
			cout << endl;
			int pos, a;
			cin >> pos >> a;
			if(pos != pos_st) {
				if(a > a_st && g[K-2] == 0) flip_gr = true;
				if(a < a_st && g[K-2] == 1) flip_gr = true;
				g[i] = 1-g[K-2];
			}
			else g[i] = g[K-2];
		}
		int M = 0;
		for(int i = 0; i < K-1; i++) if(g[i] == 0) M++;
		if(M == K-1) {
			for(int i = 0; i < N; i++) if(A[i] > a_st) M = 0;
		}
		else if(flip_gr) M = K-1-M;
		M++;
		cout << "! " << M << endl;
	}
	return 0;
}

// look at my code
// my code is amazing
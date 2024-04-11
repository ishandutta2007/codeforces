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

pair<int, int> find_border(vector<int> & pos) {
	pair<int, int> ret = {-1, -1};
	int N = pos.size();
	for(auto x : pos) {
		cout << "? " << N-1;
		for(auto y : pos) if(x != y) cout << " " << y+1;
		cout << endl;
		int a;
		cin >> a;
		if(a) {
			if(ret.ff == -1) ret.ff = x;
			else ret.ss = x;
		}
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	pair<int, int> small_val[9];
	for(int i = 1; i <= 8; i++) small_val[i] = {-1, -1};
	vector<int> free_pos;
	for(int i = 0; i < N; i++) free_pos.push_back(i);
	small_val[0] = find_border(free_pos);
	free_pos.erase(find(begin(free_pos), end(free_pos), small_val[0].ff));
	free_pos.erase(find(begin(free_pos), end(free_pos), small_val[0].ss));
	vector<int> rem[9];
	for(int k = 0; k <= 8; k++) rem[k].resize(N, -1);
	rem[2][small_val[0].ff] = 0;
	rem[2][small_val[0].ss] = 1;
	for(int i = 0; i < N; i++) if(rem[2][i] == -1) {
		cout << "? 2 " << i+1 << " " << small_val[0].ss+1 << endl;
		cin >> rem[2][i];
	}
	if(N <= 14) {
		for(int i = 1; i < N/2; i++) {
			small_val[i] = find_border(free_pos);
			free_pos.erase(find(begin(free_pos), end(free_pos), small_val[i].ff));
			free_pos.erase(find(begin(free_pos), end(free_pos), small_val[i].ss));
			if((rem[2][small_val[i].ff]-i)%2 != 0) swap(small_val[i].ff, small_val[i].ss);
		}
		vector<int> P(N);
		for(int i = 0; i < N/2; i++) {
			P[small_val[i].ff] = i+1;
			P[small_val[i].ss] = N-i;
		}
		if(P[0] > N/2) for(int i = 0; i < N; i++) P[i] = N+1-P[i];
		cout << "!";
		for(int i = 0; i < N; i++) cout << " " << P[i];
		cout << endl;
		return 0;
	}
	int a = 1;
	vector<int> mods = {3, 5, 7, 8};
	for(auto mod : mods) {
		while(a < mod) {
			vector<int> pos;
			for(auto x : free_pos) {
				bool ok_mod = true;
				for(int i = 2; i < 8; i++) if(rem[i][x] != -1)
					if((rem[i][x]-a)%i != 0) ok_mod = false;
				if(ok_mod) pos.push_back(x);
			}
			for(auto x : free_pos) {
				bool ok_mod = true;
				for(int i = 2; i < 8; i++) if(rem[i][x] != -1)
					if((rem[i][x]-(N-1-a))%i != 0) ok_mod = false;
				if(ok_mod) pos.push_back(x);
			}
			for(auto x : pos) {
				cout << "? " << free_pos.size()-1;
				for(auto y : free_pos) if(x != y) cout << " " << y+1;
				cout << endl;
				int b;
				cin >> b;
				if(b) {
					if(small_val[a].ff == -1) small_val[a].ff = x;
					else small_val[a].ss = x;
				}
			}
			if(small_val[a].ss != -1) {
				if((rem[2][small_val[a].ff]-a)%2 != 0) swap(small_val[a].ff, small_val[a].ss);
				free_pos.erase(find(begin(free_pos), end(free_pos), small_val[a].ss));
			}
			free_pos.erase(find(begin(free_pos), end(free_pos), small_val[a].ff));
			a++;
		}
		for(int r = 1; r < mod; r++) {
			int r_rm = (mod * (mod-1) / 2 + r) % mod;
			vector<int> pos_cur;
			for(int i = 0; i < mod; i++) if(i != r_rm) pos_cur.push_back(small_val[i].ff);
			for(auto x : free_pos) if(rem[mod][x] == -1) {
				pos_cur.push_back(x);
				cout << "? " << mod;
				for(auto y : pos_cur) cout << " " << y+1;
				cout << endl;
				int b;
				cin >> b;
				if(b) rem[mod][x] = r;
				pos_cur.pop_back();
			}
		}
		for(auto x : free_pos) if(rem[mod][x] == -1) rem[mod][x] = 0;
	}
	vector<int> P(N);
	for(int i = 0; i < 8; i++) {
		P[small_val[i].ff] = i+1;
		if(small_val[i].ss != -1) P[small_val[i].ss] = N-i;
	}
	for(auto x : free_pos) for(int b = 0; b < N; b++) {
		bool ok_mod = true;
		for(int i = 2; i <= 8; i++) if(rem[i][x] != -1)
			if((rem[i][x]-b)%i != 0) ok_mod = false;
		if(ok_mod) P[x] = b+1;
	}
	if(P[0] > N/2) for(int i = 0; i < N; i++) P[i] = N+1-P[i];
	cout << "!";
	for(int i = 0; i < N; i++) cout << " " << P[i];
	cout << endl;
	return 0;
}

// look at my code
// my code is amazing
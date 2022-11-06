#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define free free228
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
typedef long long base;
const int MAXN = 2e6 + 1;

struct tree {
	int n;
	vector <int> arr;
	tree() {
		n = 0;
	}
	void init() {
		arr.resize(n, 0);
	}
	void add(int i, int d) {
		assert(i < arr.size());
		//if (i == 1 && d == 1) cout << i << ' ' << n << endl;
		while (i < n) {
			arr[i] += d;
			i |= (i + 1);
		}
	}
	int get(int i) {
		int cnt = 0;
		while (i >= 0) {
			cnt += arr[i];
			i = (i & (i + 1)) - 1;
		}
		return cnt;
	}
	int get(int L, int R) {
		if (R < L) return 0;
		return get(R) - get(L - 1);
	}
};

string s;
tree box[11][11][4];
int m;

int id(char A) {
	if (A == 'A') return 0;
	if (A == 'T') return 1;
	if (A == 'G') return 2;
	return 3;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
   	cin >> s;
   	for (int c = 0; c < 4; ++c) {
   		for (int len = 1; len <= 10; ++len) {
   			for (int i = 0; i < s.size(); ++i) {
   				++box[len][i % len][c].n;
   			}
   		}
   	}
   	for (int c = 0; c < 4; ++c) {
   		for (int len = 1; len <= 10; ++len) {
   			for (int i = 0; i < len; ++i) {
   				box[len][i][c].init();
   			}
   		}
   	}
   	for (int i = 0; i < s.size(); ++i) {
   		for (int len = 1; len <= 10; ++len) {
   			// if (len == 4 && id(s[i]) == 0) {
   			// 	cout << i << ' ' << i / len << ' ' << id(s[i]) << endl;
   			// }
   			box[len][i % len][id(s[i])].add(i / len, 1);
   		// 	if (len == 4 && id(s[i]) == 0) {
		   // 		//cout << "!" << box[4][0][0].get(0, 1) << endl;
			  //  	for (int i : box[4][0][0].arr) cout << i << ' ';
			  //  	cout << endl;
		  	// }
   		}
   	}
   	// cout << box[4][0][0].get(0, 1) << endl;
   	// for (int i : box[4][0][0].arr) cout << i << ' ';
   	// cout << endl;
   	cin >> m;
   	for (int i = 0; i < m; ++i) {
   		int t;
   		cin >> t;
   		if (t == 1) {
   			int j;
   			char c;
   			cin >> j >> c;
   			--j;
   			for (int len = 1; len <= 10; ++len) {
	   			box[len][j % len][id(s[j])].add(j / len, -1);
	   			box[len][j % len][id(c)].add(j / len, 1);
	   		}
	   		s[j] = c;
   		} else {
   			int L, R;
   			string k;
   			cin >> L >> R >> k;
   			--L, --R;
   			int cnt = 0, len = k.size();
   			for (int j = 0; j < len; ++j) {
   				int Ln = L + j, Rn = R;
   				if (Ln > Rn) break;
   				while (Rn % len != Ln % len) --Rn;
   				//cout << Ln / len << ' ' << Rn / len << '/';
   				cnt += box[len][(L + j) % len][id(k[j])].get(Ln / len, Rn / len);
   			}
   			//cout << endl;
   			cout << cnt << endl;
   		}
   	}
}
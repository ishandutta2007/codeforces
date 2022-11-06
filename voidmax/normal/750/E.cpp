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
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

struct matrix {
	int a[5][5];
	matrix(int c = -1) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				a[i][j] = 1e9;
			}
		}
		for (int i = 0; i < 5; ++i) {
			a[i][i] = 0;
		}
		if (c == 2) {
			a[0][1] = 0;
			for (int i = 0; i <= 0; ++i) {
				++a[i][0];
			}
		} else if (c == 0) {
			a[1][2] = 0;
			for (int i = 0; i <= 1; ++i) {
				++a[i][1];
			}
		} else if (c == 1) {
			a[2][3] = 0;
			for (int i = 0; i <= 2; ++i) {
				++a[i][2];
			}
		} else if (c == 7) {
			a[3][4] = 0;
			for (int i = 0; i <= 3; ++i) {
				++a[i][3];
			}
		} else if (c == 6) {
			for (int i = 0; i <= 3; ++i) {
				++a[i][3];
			}
			for (int i = 0; i <= 4; ++i) {
				++a[i][4];
			}
		}
	}
};	

void print(matrix A) {
	for (int i = 0; i < 5; ++i) {
		for (int k = 0; k < 5; ++k) { 
			if (A.a[i][k] < 1e9)
				cout << A.a[i][k] << ' ';
			else 
				cout << "-" << ' ';
		}
		cout << endl;
	}
}

matrix operator * (matrix &A, matrix &B) {
	matrix C;
	for (int i = 0; i < 5; ++i)
		C.a[i][i] = 1e9;

	//print(A);
	//cout << "+++++++++++++\n";
	//print(B);
	//cout << "_____________\n";
	for (int i = 0; i < 5; ++i) {
		for (int k = i; k < 5; ++k) {
			for (int j = k; j < 5; ++j) {
				chkmin(C.a[i][j], A.a[i][k] + B.a[k][j]);
			}
		}
	}
	//print(C);
	//cout << endl;
	return C;
}

const int MAXN = 1 << 18;

int n, m;
string s;

struct seg_tree {
	matrix tree[MAXN * 2];
	matrix ans;
	void init() {
		for (int i = 0; i < n; ++i) {
			tree[i + MAXN] = matrix(s[i]);
		}
		for (int i = MAXN; --i;) {
			//cout << i * 2 << ' ' << i * 2 + 1 << endl;
			tree[i] = tree[i * 2] * tree[i * 2 + 1];
		}
	}
	void get(int i, int L, int R, int Ln, int Rn) {
		//cout << i << ' ' << L << ' ' << R << ' ' << Ln << ' ' << Rn << endl;
		if (Rn <= L || R <= Ln) return;
		if (Ln <= L && R <= Rn) {
			ans = ans * tree[i];
			return;
		}
		int M = (L + R) >> 1;
		get(i * 2, L, M, Ln, Rn);
		get(i * 2 + 1, M, R, Ln, Rn);
	}
	void get_ans(int L, int R) {
		ans = matrix();
		get(1, 0, MAXN, L, R);
	}
};

seg_tree box;

int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(0);
    //read(FILENAME);   
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n; ++i) s[i] -= '0';
    box.init();
	for (int i = 0; i < m; ++i) {
		int L, R;
		cin >> L >> R;
		--L;
		box.get_ans(L, R);
		//cout << "_________________________________\n" << endl;
		//print(box.ans);
		if (box.ans.a[0][4] <= n) {
			cout << box.ans.a[0][4] << endl;
		} else {
			cout << -1 << endl;
		}
	}
}
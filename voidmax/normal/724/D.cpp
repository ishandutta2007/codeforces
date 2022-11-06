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
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
const int MAXN = 1e5 + 10;

int n, m;
string s;
int cnt[26];
bool all[26];
int res;
int p[MAXN];
int LR[MAXN][26];

int get(int L, int R) {
	return p[R] - p[L];
}

bool check(int M) {
	For(i, 0, 26) all[i] = false;
	int bad_char;
	For(i, 0, 26) {
		if (M - cnt[i] <= 0) {
			res = M;
			bad_char = i;
			break;
		}
		M -= cnt[i];
		all[i] = true;
	}
	p[0] = 0;
	For(i, 0, n) {
		p[i + 1] = p[i];
		if (all[s[i] - 'a']) p[i + 1]++;
	} 
	int L = 0, R = m;
	int last_pos = -1;
	while (R <= s.size()) {
		if (!(get(L, R) || L <= last_pos)) {
			if (res == 0) return false;
			last_pos = LR[R - 1][bad_char];
			--res;
			if (L > last_pos) return false;
		}
		++L;
		++R;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	//read(FILENAME);
	cin >> m;
	cin >> s;
	n = s.size();
	int L = 0, R = n;
	For(i, 0, 26) LR[0][i] = -1;
	LR[0][s[0] - 'a'] = 0;
	For(i, 1, n) {
		For(j, 0, 26) LR[i][j] = LR[i - 1][j];
		LR[i][s[i] - 'a'] = i;
	}
	For(i, 0, n) cnt[s[i] - 'a']++;
	while (R - L > 1) {
		int M = (L + R) >> 1;
		if (check(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	For(i, 0, 26) {
		while (R > 0 && cnt[i] > 0) {
			cout << (char)('a' + i);
			--R, --cnt[i];
		}
	}
	cout << endl;
}
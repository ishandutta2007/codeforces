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
const int MAXN = 5e5 + 2;
const int ALPHABET = 256;
const int LOG = 19;

int n;
string s;
int p[MAXN];
int up[MAXN][LOG];
int cost[MAXN][LOG];
int cnt[MAXN];
int way[MAXN];
vector <int> st;

int get_less(int L, int s = MAXN) {
	s += L;
	int R = LOG - 1;
	int cnt = 0;
	while (R >= 0) {
		if (up[L][R] != 0 && up[L][R] <= s) {
			cnt += cost[L][R];
			L = up[L][R];
		}
		--R;
	}
	return cnt;
}

struct suf_array {
	int n;
	int c[MAXN], cn[MAXN];
	int p[MAXN], cnt[MAXN], pn[MAXN];
	int lcp[MAXN];
	suf_array() {}
	suf_array(string s) {
		s += '#';
		n = s.size();
		memset(cnt, 0, sizeof(cnt));
		For(i, 0, n)
			++cnt[s[i]];
		For(i, 0, ALPHABET) 
			cnt[i + 1] += cnt[i];
		For(i, 0, n) 
			p[--cnt[s[i]]] = i;
		int classes = 1;
		c[p[0]] = 0;
		For(i, 1, n) {
			if (s[p[i - 1]] != s[p[i]]) {
				++classes;
			}
			c[p[i]] = classes - 1;
		}
		for (int h = 0; 1 << h < n; ++h) {
			For(i, 0, n) {
				pn[i] = p[i] - (1 << h);
				if (pn[i] < 0) pn[i] += n;
			}
			memset(cnt, 0, sizeof(cnt));
			For(i, 0, n) 
				++cnt[c[pn[i]]];
			For(i, 0, classes) 
				cnt[i + 1] += cnt[i];

			Out(i, n, 0) 
				p[--cnt[c[pn[i]]]] = pn[i]; 
			classes = 1;
			cn[p[0]] = 0;
			For(i, 1, n) {
				int M1 = (p[i - 1] + (1 << h)) % n, M2 = (p[i] + (1 << h)) % n;
				if (c[M1] != c[M2] || c[p[i - 1]] != c[p[i]]) {
					++classes;
				}
				cn[p[i]] = classes - 1;
			}
			memcpy(c, cn, sizeof(c));
		}
		int l = 0;
		For(i, 0, n) {
			if (c[i] == n - 1) continue;
			l = max(0, l - 1);
			while (s[i + l] == s[p[c[i] + 1] + l])
				++l;
			lcp[c[i]] = l;
		}
	}
	long long get_ans() {
		long long cnt = 0;
		For(i, 1, n) {
			cnt += get_less(p[i]) - get_less(p[i], lcp[i - 1]);
		}
		return cnt;
	}
};

suf_array arr;

int main() {
	//read(FILENAME);
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	arr = suf_array(s);
	For(i, 0, n) {
		if (s[i] == ')') {
			if (st.size() && s[st.back()] == '(') {
				up[st.back()][0] = i + 1; 
				cost[st.back()][0] = 1;
				st.pop_back();
			} else {
				st.pb(i);
			}
		} else {
			st.pb(i);
		}
	}
	For(j, 1, LOG) {
		For(i, 0, n) {
			if (up[i][j - 1] != 0) {
				up[i][j] = up[up[i][j - 1]][j - 1];
				cost[i][j] = cost[up[i][j - 1]][j - 1] + cost[i][j - 1];
			}
		}
	}
	cout << arr.get_ans()  << endl;
}
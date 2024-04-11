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
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
	
inline int readChar();
template <class T = int> inline T readInt();
template <class T = int> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getchar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

typedef long long base;

const string FileName = "input";
const int sizeOf = 2e5;
	
int n;
base m;
int up_next[sizeOf][40];
base up_sum[sizeOf][40];
base up_min[sizeOf][40];

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
	read(FileName);
	write(FileName);
#endif
	ios::sync_with_stdio(false);
	n = readInt();
	m = readInt<base>();
	For(i, 0, n) up_next[i][0] = readInt();
	For(i, 0, n) up_sum[i][0] = up_min[i][0] = readInt();
	For(i, 1, 40) { 
		For(j, 0, n) {
			up_next[j][i] = up_next[up_next[j][i - 1]][i - 1];
			up_sum[j][i] = up_sum[up_next[j][i - 1]][i - 1] + up_sum[j][i - 1];
			up_min[j][i] = min(up_min[up_next[j][i - 1]][i - 1], up_min[j][i - 1]);
		}
	}
	For(i, 0, n) {
		int id = i;
		base R = m, L = 39;
		base ans_sum = 0, ans_min = 1e9;
		while (R > 0) {
			if ((base)1 << L > R) {
				--L;
			} else {
				ans_sum += up_sum[id][L];
				chkmin(ans_min, up_min[id][L]);
				id = up_next[id][L];
				R -= (base)1 << L;
			}
		}
		cout << ans_sum << ' ' << ans_min << '\n';
	}
}
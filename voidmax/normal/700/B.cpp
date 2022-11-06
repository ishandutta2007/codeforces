#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <long double, long double>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
#define _CRT_DISABLE_PERFCRIT_LOCKS
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

const int sizeOf = 2e5 + 10;

int n, k;
bool univ[sizeOf];
vector <int> edge[sizeOf];
int cnt[sizeOf];
base sum_cut = 0;

void dfs(int i, int p = 0) {
	for (int j: edge[i]) {
		if (j == p) continue;
		dfs(j, i);
		sum_cut += min(cnt[j], k - cnt[j]);
		cnt[i] += cnt[j];
	}
	cnt[i] += univ[i];
}

const string FileName = "input";

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
	read(FileName);
#endif
	ios::sync_with_stdio(false);
	n = readInt();
	k = readInt();
	k <<= 1;	
	For(i, 0, k) {
		univ[readInt()] = true;
	}
	For(i, 0, n - 1) {
		int L = readInt(), R = readInt();
		edge[L].pb(R);
		edge[R].pb(L);
	}	
	dfs(1);
	cout << sum_cut << endl;
}
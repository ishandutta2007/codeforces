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

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

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
        c = getChar();
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



typedef long long base;

const string FILENAME = "input";

int n, m;
vector <int> prob;
vector <long long> dp;

int check(long long M) {
	//cout << "?" << M << endl;
	multiset <int> used;
	For(i, 0, n) {
		used.insert(prob[i]);
		M += prob[i];
		//cout << M << endl;
		while (M < 0) {
			M -= *used.begin();
			used.erase(used.begin());
		}
		//cout << M << endl;

	}
	return (n - used.size());
}

int ans[200001];

int main() {
	//read(FILENAME);
	ios::sync_with_stdio(false);
	n = readInt();
	m = readInt();
	prob.resize(n);
	For(i, 0, n) prob[i] = readInt();
	vector <pair <long long, int>> arr;
	For(i, 0, m) {
		long long a = readInt <long long>();
		arr.pb({a, i});
	}
	sort(arr.rbegin(), arr.rend());
	int last = 0;
	For(i, 0, n + 1) {
		int L = last - 1, R = arr.size();
		while (R - L > 1) {
			int M = (L + R) >> 1;
			if (check(arr[M].x) <= i) {
				L = M;
			} else {
				R = M;
			}
		}
		For(j, last, L + 1) {
			ans[arr[j].y] = i;
		}
		last = L + 1;
	}
	For(i, 0, m) writeInt(ans[i], '\n');
}
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
const int LEN = 5e3 + 1;
const base INF = 1e18;


int n, s, e;
bool used[LEN];
vector <int> coor;
vector <int> jump[2][2];
int up[LEN];
base ans;

base dist(int i, int j) {
	if (i == j) return 0;
	base ans = abs(coor[i] - coor[j]);
	if (i < j) {
		return ans + jump[1][1][i] + jump[0][0][j];
	} else {
		return ans + jump[1][0][i] + jump[0][1][j];
	}
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
	 files(FileName);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> s >> e;
    --s, --e;
    For(i, 0, n) {
    	int a;
    	cin >> a;
    	coor.pb(a);
    }
    For(q, 0, 2) {
	    For(j, 0, 2) {
		    For(i, 0, n) {
		    	int a;
		    	cin >> a;
		    	jump[q][j].pb(a);
		    }
	    }
	}
	ans = dist(s, e);
	up[s] = e;
	For(i, 0, n) {
		if (i == s || i == e) continue;
		base k = INF, res;
		for(int j = s; j != e; j = up[j]) {
			base new_dist = dist(j, i) + dist(i, up[j]) - dist(j, up[j]);
			if (new_dist < k) {
				res = j;
				k = new_dist;
			}
		}
		ans += k;
		up[i] = up[res];
		up[res] = i;
	}
	cout << ans << endl;
}
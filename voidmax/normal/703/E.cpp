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

int n;
base k;
pair <short int, short int> way[1002][10001];
pair <short int, base> ans[1002][10001];
vector <base> arr;
vector <base> dev;
unordered_map <base, int> id;

void res(int i, int j) {
	if (j == 0) return;
	res(way[i][j].x, way[i][j].y);
	if (way[i][j].y != j) {
		writeInt(way[i][j].x + 1, ' ');
	}
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
	 files(FileName);
#endif
    ios::sync_with_stdio(false);
    n = readInt();
    k = readInt<base>();
    For(i, 0, n) {
    	arr.pb(readInt<base>());
    }
    if (k == 1) {
    	int id = 0;
    	For(i, 0, n) {
    		if (arr[i] < arr[id]) {
    			id = i;
    		}
     	}
     	cout << 1 << endl;
     	cout << id + 1 << endl;
    	return 0;
    }
    For(j, 1, 2e6 + 1) {
    	if ((base)j * j == k) {
    		dev.pb(j);
    	}
    	if (j * j >= k) break;
    	if (k % j == 0) {
    		dev.pb(k / j);
    		dev.pb(j);
    	}
    }
    sort(dev.begin(), dev.end());
    id.reserve(dev.size() * 2);
    For(i, 0, dev.size()) id[dev[i]] = i;
    For(i, 0, n + 1) For(j, 0, dev.size()) ans[i][j] = {1002, 0};
    ans[0][0] = {0, 0};
    For(i, 0, n) {
    	For(j, 0, dev.size()) {
    		if (ans[i][j].x == 1002) continue;
    		base m = __gcd(arr[i], k / dev[j]);
    		base nm = dev[j] * m;
    		if (ans[i + 1][j] > ans[i][j]) {
    			way[i + 1][j] = {i, j};
    			ans[i + 1][j] = ans[i][j];
    		}
    		int q = id[nm];
    		ans[i][j].x += 1;
    		ans[i][j].y += arr[i];
    		if (ans[i + 1][q] > ans[i][j]) {
    			way[i + 1][q] = {i, j};
    			ans[i + 1][q] = ans[i][j];
    		}
    	}
    }
    if (ans[n][(int)dev.size() - 1].x == 1002) {
    	cout << -1 <<  endl;
    	return 0;
    }
    writeInt(ans[n][(int)dev.size() - 1].x, '\n');
    res(n, (int)dev.size() - 1);
    writeChar('\n');
}
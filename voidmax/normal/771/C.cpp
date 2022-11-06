/*
  !










*/
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
#include <stack>
#include <deque>
 
  
  
using namespace std;
  
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
/** Interface */
  
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
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
  
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
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
  
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
  
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
const int MAXN = 200001;

int n, k;
vector<int> v[MAXN];
long long ans = 0;


void dfs(int u, int pr, vector<long long> &cnt, vector<long long> &cnt1) {
    long long ans1 = 0;
    for (auto h: v[u]) {
        if (h != pr) {
            vector<long long> cnt2, cnt3;
            cnt2.resize(k, 0);
            cnt3.resize(k, 0);
            dfs(h, u, cnt2, cnt3);
            vector<long long> ncnt2;
            vector<long long> ncnt3;
            ncnt2.resize(k, 0);
            ncnt3.resize(k, 0);
            for (int i = 0; i < k; i++) {
                if (i != k - 1) {
                    ncnt3[i + 1] += cnt3[i];
                    ncnt2[i + 1] += cnt2[i];
                } else {
                    ncnt3[0] += cnt3[i];
                    ncnt2[0] += cnt2[i] + cnt3[i];
                }
            }
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    ans1 += 1LL * cnt[i] * ncnt3[j] + 1LL * cnt1[i] * ncnt2[j] + (i + j ? 1LL * ((i + j + k - 1) / k) * cnt1[i] * ncnt3[j]: 0LL);
                }
            }
            for (int i = 0; i < k; i++) {
                cnt[i] += ncnt2[i];
                cnt1[i] += ncnt3[i];
            }
        }
    }
    //cout << ans1 << ' ' << u + 1 << endl;
    ans += ans1;
    for (int i = 0; i < k; i++) {
        ans += cnt[i] + (i ? cnt1[i]: 0LL);
    }
    cnt1[0]++;
}


int main() {
    n = readInt(), k = readInt();
    for (int i = 0; i < n - 1; i++) {
        int a = readInt(), b = readInt();
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<long long> cnt, cnt1;
    cnt.resize(k, 0);
    cnt1.resize(k, 0);
    dfs(0, -1, cnt, cnt1);
    cout << ans << '\n';
    return 0;
}
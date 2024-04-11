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
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
          
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
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
const int MAXN = 2e5 + 1;
typedef pair<int, int> point;

int X, Y, Z;
string dp[256][3];

int get(vector<int> a) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans *= 2;
        ans += a[i];
    }
    return ans;
}

set<pair<int, point>> que;

void check(int m, int t, string s) {
    if (dp[m][t].size() == 0) {
        dp[m][t] = s;
        que.insert(mp(s.size(), mp(m, t)));
    } else if (dp[m][t].size() > s.size() || (s.size() == dp[m][t].size() && s < dp[m][t])) {
        que.erase(mp(dp[m][t].size(), mp(m, t)));
        dp[m][t] = s;
        que.insert(mp(dp[m][t].size(), mp(m, t)));
    } 
}

int n;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read(FILENAME);
    dp[X = get({0, 0, 0, 0, 1, 1, 1, 1})][0] = "x";
    dp[Y = get({0, 0, 1, 1, 0, 0, 1, 1})][0] = "y";
    dp[Z = get({0, 1, 0, 1, 0, 1, 0, 1})][0] = "z";
    que.insert(mp(1, mp(X, 0)));
    que.insert(mp(1, mp(Y, 0)));
    que.insert(mp(1, mp(Z, 0)));
    while (que.size()) {
        auto r = *que.begin();
        que.erase(r);
        auto v = r.y;
        if (v.y == 0) {
            int u = v.x ^ (256 - 1);
            check(u, 0, "!" + dp[v.x][v.y]);
            for (int i = 0; i < 256; ++i) {
                if (dp[i][0].size()) {
                    check(i & v.x, 1, dp[i][0] + "&" + dp[v.x][0]);
                    check(i & v.x, 1, dp[v.x][0] + "&" + dp[i][0]);
                    check(i | v.x, 2, dp[i][0] + "|" + dp[v.x][0]);
                    check(i | v.x, 2, dp[v.x][0] + "|" + dp[i][0]);
                } 
                if (dp[i][1].size()) {
                    check(i & v.x, 1, dp[i][1] + "&" + dp[v.x][0]);
                    check(i & v.x, 1, dp[v.x][0] + "&" + dp[i][1]);
                    check(i | v.x, 2, dp[i][1] + "|" + dp[v.x][0]);
                    check(i | v.x, 2, dp[v.x][0] + "|" + dp[i][1]);
                } 
                if (dp[i][2].size()) {
                    check(i | v.x, 2, dp[i][2] + "|" + dp[v.x][0]);
                    check(i | v.x, 2, dp[v.x][0] + "|" + dp[i][2]);
                }
            }
        } else if (v.y == 1) {
            check(v.x, 0, "(" + dp[v.x][v.y] + ")");
            for (int i = 0; i < 256; ++i) {
                if (dp[i][0].size()) {
                    check(i & v.x, 1, dp[i][0] + "&" + dp[v.x][1]);
                    check(i & v.x, 1, dp[v.x][1] + "&" + dp[i][0]);
                    check(i | v.x, 2, dp[i][0] + "|" + dp[v.x][1]);
                    check(i | v.x, 2, dp[v.x][1] + "|" + dp[i][0]);
                } 
                if (dp[i][1].size()) {
                    check(i & v.x, 1, dp[i][1] + "&" + dp[v.x][1]);
                    check(i & v.x, 1, dp[v.x][1] + "&" + dp[i][1]);
                    check(i | v.x, 2, dp[i][1] + "|" + dp[v.x][1]);
                    check(i | v.x, 2, dp[v.x][1] + "|" + dp[i][1]);
                } 
                if (dp[i][2].size()) {
                    check(i | v.x, 2, dp[i][2] + "|" + dp[v.x][1]);
                    check(i | v.x, 2, dp[v.x][1] + "|" + dp[i][2]);
                }
            }
        } else {
            check(v.x, 0, "(" + dp[v.x][v.y] + ")");
            for (int i = 0; i < 256; ++i) {
                if (dp[i][0].size()) {
                    check(i | v.x, 2, dp[i][0] + "|" + dp[v.x][2]);
                    check(i | v.x, 2, dp[v.x][2] + "|" + dp[i][0]);
                } 
                if (dp[i][1].size()) {
                    check(i | v.x, 2, dp[i][1] + "|" + dp[v.x][2]);
                    check(i | v.x, 2, dp[v.x][2] + "|" + dp[i][1]);
                } 
                if (dp[i][2].size()) {
                    check(i | v.x, 2, dp[i][2] + "|" + dp[v.x][2]);
                    check(i | v.x, 2, dp[v.x][2] + "|" + dp[i][2]);
                }
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int id = 0;
        for (char c : s) {
            id *= 2;
            id += c - '0';
        }
        string ans = dp[id][0];
        if (dp[id][1].size() < ans.size() || (dp[id][1].size() == ans.size() && dp[id][1] < ans)) {
            ans = dp[id][1];
        }
        if (dp[id][2].size() < ans.size() || (dp[id][2].size() == ans.size() && dp[id][2] < ans)) {
            ans = dp[id][2];
        }
        cout << ans << '\n';
    }
}
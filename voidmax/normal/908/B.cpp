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
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }


const string FILENAME = "input";
typedef pair<int, int> point;
typedef long double base;

const int MAXN = 101;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;

int ans;
point s, f;
string func;
bool good[MAXN][MAXN];

vector<int> dir;


int main() {
	srand(time(0));
    //read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c != '#') good[i][j] = true;
            if (c == 'S') s = {i, j};
            if (c == 'E') f = {i, j};
        }
    }
    cin >> func;
    for (int d = 0; d < 4; ++d) dir.pb(d);
    do {
        point a = s;
        for (int j = 0; j < func.size() && good[a.x][a.y] && a != f; ++j) {
            a = {a.x + dx[dir[func[j] - '0']], a.y + dy[dir[func[j] - '0']]};
        }
        if (a == f) ++ans;
    } while (next_permutation(dir.begin(), dir.end()));
    cout << ans << endl;
}
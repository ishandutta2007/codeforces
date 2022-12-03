#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

bool a[64][64];

int d[64][1<<12];

int dy[5] = {-1, 1, 0, 0, 0};
int dx[5] = {0, 0, -1, 1, 0};

int n, m;

const int inf = -1u/4;

bool check(int y, int x) {
    REP (dir, 5) {
        int q = y + dy[dir];
        int w = x + dx[dir];
        if (q < 0 || w < 0 || q >= n || w >= m) continue;
        if (a[q][w]) return true;
    }
    return false;
}

int solve(int y, int x, int num, int mask) {    
    int & res = d[num][mask];
    if (res != -1) 
        return res;
    res = inf;
    if (y >= n) {
        REP (j, m)
            if (!check(n-1, j)) return res;        
        return res = 0;
    }
    a[y][x] = true;
    if (!y || check(y-1, x))
        res = min (res, 1+solve(y + (x+1) / m, (x+1) % m, num+1, ((mask * 2) & ((1<<(2*m))-1)) + 1));
    a[y][x] = false;
    
    if (!y || check(y-1, x))
    res = min (res, solve(y + (x+1) / m, (x+1) % m, num+1, ((mask * 2) & ((1<<(2*m))-1)) + 0));
    return res;
}

int main () {
    #ifdef LOCAL
    	freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    cin >> n >> m;
    if (n < m) swap(n, m);
    memset(d, -1, sizeof (d));
    cout << (n*m-solve(0, 0, 0, 0)) << endl;    
    return 0;
}
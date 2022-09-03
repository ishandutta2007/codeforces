#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

int a[100000][3];
int b[100000][3];
int was[100000][3];
int res[100000][3];

bool cool (int i, int l, int j, int r) {
    re b[i][l] < a[j][r];
}

int go (int i, int l) {
    if (i == n) re 0;
    if (was[i][l]) re res[i][l];
    was[i][l] = 1;
    int cur = -1e9;
    for (int r = 0; r < 3; r++)
        if (cool (i - 1, l, i, r))
            cur = max (cur, go (i + 1, r) + int (r != 1));
    re res[i][l] = cur;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, h;
        scanf ("%d%d", &x, &h);
        a[i][0] = x - h;
        b[i][0] = x;
        a[i][1] = x;
        b[i][1] = x;
        a[i][2] = x;
        b[i][2] = x + h;
    }   
    cout << go (1, 0) + 1 << endl;
    return 0;
}
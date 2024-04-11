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
int a, b;
int dx[101], dy[101];
string s;

int main () {
    cin >> a >> b;
    cin >> s;
    dx[0] = dy[0] = 0;
    n = sz (s);
    for (int i = 0; i < n; i++) {
        dx[i + 1] = dx[i] + int (s[i] == 'R') - int (s[i] == 'L');
        dy[i + 1] = dy[i] + int (s[i] == 'U') - int (s[i] == 'D');
    }
    for (int i = 0; i < n; i++) {
        int A = a - dx[i], B = b - dy[i];
        if (A == 0 && B == 0) {
            printf ("Yes\n");
            re 0;
        }
        if (A > 0 && dx[n] <= 0 || A < 0 && dx[n] >= 0 || A == 0 && dx[n] != 0) continue;
        if (B > 0 && dy[n] <= 0 || B < 0 && dy[n] >= 0 || B == 0 && dy[n] != 0) continue;
        if (dx[n] != 0 && abs (A) % abs (dx[n]) != 0) continue;
        if (dy[n] != 0 && abs (B) % abs (dy[n]) != 0) continue;
        if (dx[n] == 0 || dy[n] == 0) {
            printf ("Yes\n");
            re 0;
        }
        if (abs (A) / abs (dx[n]) == abs (B) / abs (dy[n])) {
            printf ("Yes\n");
            re 0;
        }
    }
    printf ("No\n");
    return 0;
}
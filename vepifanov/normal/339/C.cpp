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
int x[1000];
int was[1000][11][11];
string s;

int go (int i, int dif, int last) {
    if (i > 0 && dif <= 0 || dif > 10) re 0;
    if (i == m) {
        printf ("YES\n");
        for (int j = 0; j < m; j++)
            printf ("%d ", x[j]);
        printf ("\n");
        re 1;
    }
    if (was[i][dif][last]) re 0;
    was[i][dif][last] = 1;
    for (int j = 0; j < 10; j++)
        if (s[j] == '1' && j != last) {
            x[i] = j + 1;
            if (go (i + 1, j + 1 - dif, j))
                re 1;
        }
    re 0;
}

int main () {
    cin >> s;
    scanf ("%d", &m);
    if (!go (0, 0, 10)) printf ("NO\n");
    return 0;
}
#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
int res[4002][4002];
int na[4002][26];
int nb[4002][26];
int last[26];
int ta, tb, tc, td;
string sa, sb;

int main() {
    cin >> ta >> tb >> tc >> td;
    cin >> sa >> sb;
    int n = sz (sa);
    int m = sz (sb);
    for (int i = 0; i < 26; i++) last[i] = m;
    for (int i = m; i >= 0; i--) {
        if (i < m) last[sb[i] - 'a'] = i;
        for (int j = 0; j < 26; j++)
            nb[i][j] = last[j];
    }
    for (int i = 0; i < 26; i++) last[i] = n;
    for (int i = n; i >= 0; i--) {
        if (i < n) last[sa[i] - 'a'] = i;
        for (int j = 0; j < 26; j++)
            na[i][j] = last[j];
    }
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            res[i][j] = 1e9; 
    res[n][m] = 0;
    for (int i = n; i >= 0; i--)
        for (int j = m; j >= 0; j--) {
            if (i < n && j < m) res[i][j] = min (res[i][j], res[i + 1][j + 1] + tc * int (sa[i] != sb[j]));
            if (i < n) res[i][j] = min (res[i][j], res[i + 1][j] + tb);
            if (j < m) res[i][j] = min (res[i][j], res[i][j + 1] + ta);
            if (i + 2 <= n && j + 2 <= m) {
                int ca = sb[j] - 'a';
                int cb = sa[i] - 'a';
                if (na[i + 1][ca] < n && nb[j + 1][cb] < m)
                    res[i][j] = min (res[i][j], res[na[i + 1][ca] + 1][nb[j + 1][cb] + 1] + td + (na[i + 1][ca] - i - 1) * tb + (nb[j + 1][cb] - j - 1) * ta);
            }
        }
    printf ("%d\n", res[0][0]);
    return 0;
}
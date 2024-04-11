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
int g[26][26];
int res[101][101][26];
int was[101][101][26];
string s;

int go (int i, int j, int k) {
    if (j < 0) re -1e9;
    if (i + 1 == sz (s)) re 0;
    if (was[i][j][k]) re res[i][j][k];
    was[i][j][k] = 1;
    int cur = -1e9;
    for (int l = 0; l < 26; l++)
        cur = max (cur, go (i + 1, j - int (s[i + 1] - 'a' != l), l) + g[k][l]);
    re res[i][j][k] = cur;  
}

int main() {
    cin >> s >> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        g[a - 'a'][b - 'a'] = c;
    }
    int ans = -1e9;
    for (int i = 0; i < 26; i++) ans = max (ans, go (0, m - int (s[0] - 'a' != i), i));
    printf ("%d\n", ans);
    return 0;
}
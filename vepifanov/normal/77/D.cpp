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

const string dom[2][7] = {
    {".........","....O....","O.......O","O...O...O","O.O...O.O","O.O.O.O.O","OOO...OOO"},
    {".........","....O....","..O...O..","..O.O.O..","O.O...O.O","O.O.O.O.O","O.OO.OO.O"}};

const int mod = 1000000007;

int n;
int m;
char w[1002][1002];
int g[250][250];
int can[250], can2[250];
int cnt[251], res[251];

int get (int i, int j) {
    string s = "";
    for (int p = 0; p < 3; p++)
        for (int q = 0; q < 3; q++)
            s += w[i + p][j + q];
    int res = 0;
    for (int p = 0; p < 2; p++)
        for (int q = 0; q < 7; q++)
            if (s == dom[p][q])
                res |= (p + 1);
    re res;
}

int main() {
    scanf ("%d%d", &n, &m); 
    gets (w[0]);
    for (int i = 0; i < 4 * n + 1; i++) gets (w[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            g[i][j] = get (4 * i + 1, 4 * j + 1);
        for (int j = 0; j < m; j++) {
            can[j] = int (n % 2 == 0);
            for (int i = 0; i < n; i++) can[j] &= int ((g[i][j] & 2) != 0);
        }
    for (int j = 0; j + 1 < m; j++) {
        memset (cnt, 0, sizeof (cnt));
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            if (g[i][j] & g[i][j + 1] & 1)
                cnt[i + 1] = (cnt[i + 1] + cnt[i]) % mod;
            if (i + 1 < n && int (g[i][j] & g[i + 1][j] & g[i][j + 1] & g[i + 1][j + 1] & 2))   
                cnt[i + 2] = (cnt[i + 2] + cnt[i]) % mod;
        }
        can2[j] = (cnt[n] - can[j] * can[j + 1] + mod) % mod;
    }
    memset (res, 0, sizeof (res));
    res[0] = 1;
    for (int j = 0; j < m; j++) {
        if (can[j]) res[j + 1] = (res[j + 1] + res[j]) % mod;
        if (j + 1 < m) res[j + 2] = (res[j + 2] + (ll)res[j] * can2[j]) % mod;
    }
    printf ("%d\n", res[m]);
    return 0;
}
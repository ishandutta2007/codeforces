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

const int mod = 1000000000 + 9;

int n;
int m;
int res[1101][11][11][11];
int was[1101][11][11][11];
int use[11][11][11];
int next[11][11][11];
int p[11][11];
int l[11];
string s[11];

int go (int i, int p, int q, int r) {
    if (r > 9) re 0;
//  printf ("%d %d %d %d:\n", i, p, q, r);
    if (i == 0) re int (r == 0);
    if (was[i][p][q + 1][r]) re res[i][p][q + 1][r];
    was[i][p][q + 1][r] = 1;
    int cur = 0;
    int pf[10], npf[10];
    for (int t = 0; t < m; t++) {
        pf[t] = use[p][q][t];
        if (pf[t] == q && t < p) pf[t] = ::p[t][pf[t]];
//      printf ("%d\n", pf[t]);
    }
    for (int c = 0; c < 4; c++) {
        for (int j = 0; j < m; j++) {
            npf[j] = next[j][pf[j] + 1][c];
//          printf ("%d\n", npf[j]);
        }   
        int nr = r + 1;
        for (int j = 0; j < m; j++)
            if (npf[j] + 1 == l[j]) {
                if (l[j] >= nr) nr = 0;
                npf[j] = ::p[j][npf[j]];
            }
        int np = 0, nq = npf[0];
        for (int j = 0; j < m; j++)
            if (npf[j] > nq) {
                np = j;
                nq = npf[j];
            }
/*      printf ("%d %d %d %d: ", i, p, q, r);
        for (int j = 0; j < m; j++) printf ("%d ", pf[j]);
        printf (" -%d>  ", c);
        printf ("%d %d %d %d:", i - 1, np, nq, nr);
        for (int j = 0; j < m; j++) printf ("%d ", npf[j]);
        printf ("\n");*/
        cur = cur + go (i - 1, np, nq, nr);             
        if (cur >= mod) cur -= mod;
    }
//  printf ("%d %d %d %d = %d\n", i, p, q, r, cur);
    re res[i][p][q + 1][r] = cur;
}

char get (char x) {
    if (x == 'A') re 'a';
    if (x == 'C') re 'b';
    if (x == 'G') re 'c';
    re 'd';
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> s[i];
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < sz (s[i]); j++) s[i][j] = get (s[i][j]);
    for (int i = 0; i < m; i++) {
        l[i] = sz (s[i]);
        p[i][0] = -1;
        for (int j = 1; j < l[i]; j++) {
            int k = p[i][j - 1];
            while (k >= 0 && s[i][k + 1] != s[i][j]) k = p[i][k];
            if (s[i][k + 1] == s[i][j]) k++;
            p[i][j] = k;
        }
        for (char c = 'a'; c <= 'd'; c++)
            for (int j = -1; j + 1 < l[i]; j++) {
                int k = j;
                while (k >= 0 && s[i][k + 1] != c) k = p[i][k];
                if (s[i][k + 1] == c) k++;
                next[i][j + 1][c - 'a'] = k;
            }       
    }
    for (int i = 0; i < m; i++) 
        for (int j = -1; j < l[i]; j++) 
            for (int k = 0; k < m; k++)
                for (int t = min (l[k] - 2, j); t >= -1; t--) {
                    int ok = 1;
                    for (int l = 0; l <= t; l++)
                        if (s[i][j - l] != s[k][t - l])
                            ok = 0;
                    if (ok) {
                        use[i][j][k] = t;
                        break;
                    }
                }
    printf ("%d\n", go (n, 0, -1, 0));
    return 0;
}
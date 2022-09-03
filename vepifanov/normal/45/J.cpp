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
int g[100][100];
int p[10];

int main() {
    scanf ("%d%d", &n, &m); 
    if (n <= 3 && m <= 3) {
        for (int i = 0; i < n * m; i++) p[i] = i + 1;
        do {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    g[i][j] = p[i * m + j];
            int ok = 1;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    if (i + 1 < n && abs (g[i][j] - g[i + 1][j]) == 1) ok = 0;
                    if (j + 1 < m && abs (g[i][j] - g[i][j + 1]) == 1) ok = 0;
                }
            if (ok) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++)
                        printf ("%d ", g[i][j]);
                    printf ("\n");
                }
                re 0;
            }
        } while (next_permutation (p, p + n * m));
    } else
    if (n >= 4) {
        int k = 0;
        for (int i = 2; i <= n; i += 2) {
            for (int j = 0; j < m; j++) g[k][j] = i + j * n;
            k++;
        }
        for (int i = 1; i <= n; i += 2) {
            for (int j = 0; j < m; j++) g[k][j] = i + j * n;
            k++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf ("%d ", g[i][j]);
            printf ("\n");
        }
        re 0;
    } else 
    if (m >= 4) {
        int k = 0;
        for (int i = 2; i <= m; i += 2) {
            for (int j = 0; j < n; j++) g[j][k] = i + j * m;
            k++;
        }
        for (int i = 1; i <= m; i += 2) {
            for (int j = 0; j < m; j++) g[j][k] = i + j * m;
            k++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf ("%d ", g[i][j]);
            printf ("\n");
        }
        re 0;
    }
    printf ("-1\n");
    return 0;
}
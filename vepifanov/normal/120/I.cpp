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

const string g[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int n;
int m;
int cnt[10];
int w[10][10];
int x[200000];
int h[200001];
int u[200001];
int now;
string s;

int put (int i, int j) {
    x[i] = j;
    h[i + 1] = h[i];
    u[i + 1] = u[i] + cnt[j]; 
    if (i >= m) h[i + 1] += w[j][x[i - m]];
    re 0;
}

int go (int i) {
    if (i == n) re 0;
    for (int j = 0; j < 10; j++) {
        int cur = 0;
        if (i >= m) cur = h[i] + w[j][x[i - m]] + u[m] - u[i - m + 1]; else cur = u[i] + cnt[j] + 7 * (m - i - 1);
        if (cur > now) {
            put (i, j);
            go (i + 1);
            re 0;
        }
        }
        re 0;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    for (int i = 0; i < 10; i++) {
        cnt[i] = 0;
        for (int j = 0; j < 7; j++) cnt[i] += g[i][j] - '0';
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 7; k++)
                w[i][j] += (g[i][k] - '0') * (g[j][k] - '0');
    }
    cin >> s;
    n = sz (s);
    for (int i = 0; i < n; i++) x[i] = s[i] - '0';
    m = n / 2;
    h[0] = u[0] = 0;
    for (int i = 0; i < n; i++) put (i, x[i]);
    now = h[n];
    for (int i = n - 1; i >= 0; i--)
        for (int j = x[i] + 1; j < 10; j++) {
            int cur = 0;
            if (i >= m) cur = h[i] + w[j][x[i - m]] + u[m] - u[i - m + 1]; else cur = u[i] + cnt[j] + 7 * (m - i - 1);
            if (cur > now) {
                put (i, j);
                go (i + 1);
                for (int k = 0; k < n; k++) printf ("%d", x[k]);
                printf ("\n");
                re 0;
            }
                }
        printf ("-1\n");
    return 0;
}
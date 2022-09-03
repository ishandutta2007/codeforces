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

const int p[4] = {2, 3, 5, 7};

int n;
int m;
string s;
int cnt[10][4];
int was[106][61][16][16];
int res[106][61][16][16];
int x[4];

int go () {
    if (x[0] + x[1] + x[2] + x[3] == 0) re 0;
    if (was[x[0]][x[1]][x[2]][x[3]] == 1) re res[x[0]][x[1]][x[2]][x[3]];
    was[x[0]][x[1]][x[2]][x[3]] = 1;
    int cur = -1e9;
    for (int j = 2; j < 10; j++) {
        int ok = 1;
        for (int k = 0; k < 4; k++)
            if (cnt[j][k] > x[k])
                ok = 0;
        if (ok) {
            for (int k = 0; k < 4; k++)
                x[k] -= cnt[j][k];
            cur = max (cur, go () + 1);
            for (int k = 0; k < 4; k++)
                x[k] += cnt[j][k];
        }
    }
    re res[x[0]][x[1]][x[2]][x[3]] = cur;
}

int out () {
    if (x[0] + x[1] + x[2] + x[3] == 0) {
        printf ("\n");
        re 0;
    }   
    int cur = res[x[0]][x[1]][x[2]][x[3]];
    for (int j = 9; j > 1; j--) {
        int ok = 1;
        for (int k = 0; k < 4; k++)
            if (cnt[j][k] > x[k])
                ok = 0;
        if (ok) {
            for (int k = 0; k < 4; k++)
                x[k] -= cnt[j][k];
            int tmp = go () + 1;
            if (tmp == cur) {
                printf ("%d", j);
                out ();
                break;
            } else {
                for (int k = 0; k < 4; k++)
                    x[k] += cnt[j][k];
            }
        }
    }
    re 0;
}

int main () {
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < 4; j++) {
            int I = i, k = 0;
            while (I % p[j] == 0) {
                I /= p[j];
                k++;
            }
            cnt[i][j] = cnt[i - 1][j] + k;
        }
    }
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            x[j] += cnt[s[i] - '0'][j];
    go ();
    out ();
    return 0;
}
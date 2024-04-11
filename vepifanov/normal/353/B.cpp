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
int x[200];
int y[200];
int res[200];
vi u, v;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        scanf ("%d", &x[i]);
        y[i] = x[i];
    }
    sort (y, y + 2 * n);
    for (int i = 0; i < 2 * n; ) {
        int j = i;
        while (j < 2 * n && y[j] == y[i]) j++;
        if (j == i + 1) v.pb (y[i]); else u.pb (y[i]);
        i = j;
    }
    int a = sz (u) + (sz (v) + 1) / 2;
    int b = sz (u) + sz (v) / 2;
    printf ("%d\n", a * b);
    int p = n, q = n;
    for (int i = 0; i < sz (v); i++)
        if (i < (sz (v) + 1) / 2) {
            for (int j = 0; j < 2 * n; j++)
                if (x[j] == v[i]) {
                    res[j] = 1;
                    break;
                }
            p--;
        } else {
            for (int j = 0; j < 2 * n; j++)
                if (x[j] == v[i]) {
                    res[j] = 2;
                    break;
                }
            q--;
        }
    for (int i = 0; i < sz (u); i++) {
        for (int j = 0; j < 2 * n; j++)
            if (x[j] == u[i]) {
                res[j] = 1;
                x[j] = 0;
                break;
            }
        p--;
        for (int j = 0; j < 2 * n; j++)
            if (x[j] == u[i]) {
                res[j] = 2;
                x[j] = 0;
                break;
            }
        q--;
    }
    for (int i = 0; i < 2 * n; i++)
        if (res[i] == 0) {
            if (p) {
                res[i] = 1;
                p--;
            } else {
                res[i] = 2;
                q--;
            }
        }   
    for (int i = 0; i < 2 * n; i++)
        printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}
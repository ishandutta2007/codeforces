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
int x[40], y[40], q[1000];

int main() {
    scanf ("%d%d", &n, &m); 
    for (int i = 0; i < m; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) y[j] = x[j];
        q[0] = i;
        y[i]--;
        int ok = 1;
        for (int j = 1; j < n; j++) {
            int k = -1;
            for (int t = 0; t < m; t++)
                if (y[t] && (t != q[j - 1] && (j + 1 < n || t != q[0])) && (k == -1 || y[k] < y[t]))
                    k = t;
            if (k == -1) { ok = 0; break; }
            y[k]--;
            q[j] = k;
        }
        if (ok) {
            for (int j = 0; j < n; j++) printf ("%d ", q[j] + 1);
            printf ("\n");
            re 0;
        }
    }
    printf ("-1\n");
    return 0;
}
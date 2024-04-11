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

const int res[10] = {1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975};

int n;
int m;
int x[10];
int c[10];

int go (int i, int j) {
    if (i == n) {
        for (int k = 0; k < j; k++) {
            if (k > 0) printf (",");
            printf ("{");
            int f = 1;
            for (int l = 0; l < n; l++) 
                if (x[l] == k) {
                    if (!f) printf (",");
                    f = 0;
                    printf ("%d", l + 1);
                }
            printf ("}");
        }
        printf ("\n");
        re 0;
    }
    int q = c[i];
    c[i] ^= 1;
    for (int l = 0; l <= j; l++) {
        int k = l;
        if (q) k = j - l;
        x[i] = k;
        go (i + 1, j + int (k == j));
    }
    re 0;
}

int main() {
    scanf ("%d", &n);
    x[0] = 0;
    printf ("%d\n", res[n - 1]);
    go (1, 1);
    return 0;
}
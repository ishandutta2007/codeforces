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
int m, r;
int a, b, k;
int q[10000];

int prime (int x) {
    if (x == 1) re 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            re 0;
    re 1;
}

int go (int a, int i, int j, int q) {
    if (i == r || j > a / ::q[i]) re (a / j) * q;
    int ans = go (a, i + 1, j, q);
    if (j <= a / ::q[i]) ans += go (a, i + 1, j * ::q[i], -q);
    re ans;
}

int main() {
    scanf ("%d%d%d", &a, &b, &k);
    if (!prime (k)) {
        printf ("0\n");
        re 0;
    }
    if (k >= 45000) {
        printf ("%d\n", int (k >= a && k <= b) + int ((ll)k * k >= a && (ll)k * k <= b));
        re 0;
    }   
    r = 0;
    for (int i = 2; i < k; i++)
        if (prime (i))
            q[r++] = i;
    printf ("%d\n", go (b, 0, k, 1) - go (a - 1, 0, k, 1));
    return 0;
}
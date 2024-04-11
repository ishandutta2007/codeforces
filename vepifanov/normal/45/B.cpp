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
int g[100001], v[100001], b[100001], res[100001], d[100001];

int main() {
    scanf ("%d%d", &n, &m); 
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &g[i]);
        d[i] = 0;
    }
    for (int i = 1; i <= m; i++) scanf ("%d", &v[i]);
    for (int i = 1; i <= m; i++) scanf ("%d", &b[i]);
    res[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = (res[i - 1] + v[i] - 1) % n + 1; b[i] > d[j]; j = g[j]) {
            res[i] += int (d[j] == 0);
            d[j] = b[i];
            b[i]--;
        }
        printf ("%d\n", res[i]);
    }
    return 0;
}
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

int main() {
    int a, b, c;
    scanf ("%d%d%d", &a, &b, &c);
    if (a == 0) a = -3;
    if (b == 0) b = -3;
    if (c == 0) c = -3;
    printf ("%d\n", 30 + max (max ((a - 1) / 2 * 3, (b - 1) / 2 * 3 + 1), (c - 1) / 2 * 3 + 2));
    return 0;
}
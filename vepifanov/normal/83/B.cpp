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
ll m;
int x[100000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += x[i];
    if (m > sum) {
        printf ("-1\n");
        re 0;
    } else
    if (m == sum) {
        printf ("\n");
        re 0;
    }
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int s = (l + r) / 2;
        sum = 0;
        for (int i = 0; i < n; i++) sum += min (s, x[i]);
        if (sum <= m) l = s; else r = s;
    }
    sum = 0;
    for (int i = 0; i < n; i++) sum += min (l, x[i]);
    int i;
    for (i = 0; i < n && sum < m; i++)
        if (x[i] > l)
            sum++;
    for (int j = i; j < n; j++)
        if (x[j] > l)
            printf ("%d ", j + 1);
    for (int j = 0; j < i; j++)
        if (x[j] > l + 1)
            printf ("%d ", j + 1);
    printf ("\n");
    return 0;
}
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define pii pair <int, LL>
#define piii pair <pii, int>
using namespace std;

const int N = 111;
const LL INF = 1LL << 60;

int a[N];
vector <int> g[N];

int main () {
    int n, k;
    int mx = 0, mn = 1e9;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        mx = max (mx, a[i]);
        mn = min (mn, a[i]);
        for (int j = 1, c = 1; j <= a[i]; j++) {
            g[i].push_back (c);
            if (++c > k) c = 1;
        }
    }
    if (mx - mn > k) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int) g[i].size (); j++) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}
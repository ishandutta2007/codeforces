#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;

const int N = 110;
int a[N];

int main () {
    int n, m, r = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &r);
        a[r]++;
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            res += a[i] * a[j];
        }
    }
    cout << res << endl;
}
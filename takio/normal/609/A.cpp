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
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    sort (a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--) {
        m -= a[i];
        r++;
        if (m <= 0) break;
    }
    cout << r << endl;
}
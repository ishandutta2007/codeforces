#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    vector<string> a;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
        string p = "face";
    sort(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            string s = "";
            s += a[i][j];
            s += a[i + 1][j];
            s += a[i][j + 1];
            s += a[i + 1][j + 1];
            sort(s.begin(), s.end());
            if (s == p) ans++;
        }
    }
    cout << ans << endl;
}
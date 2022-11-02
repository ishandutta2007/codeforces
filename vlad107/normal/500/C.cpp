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

const int N = 500500;

vector<int> v;
int w[N], a[N], n, m, used[N];

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        --x;
        a[i] = x;
        if (!used[x]) {
            v.push_back(x);
            used[x] = true;
        }
    }
    reverse(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int x = a[i];
        int j;
        for (j = v.size() - 1; j >= 0; j--) {
            if (v[j] == x) {
                break;
            }
            ans += w[v[j]];
        }
        for (int e = j + 1; e < v.size(); e++) v[e - 1] = v[e];
        v.back() = x;
    }
    cout << ans << endl;
}
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

const int N = 2111111;

int f[N], last[N], a[N], n, ans;

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        f[a[i]] = 1;
    }
    last[0] = 0;
    for (int i = 1; i < N; i++) {
        last[i] = last[i - 1];
        if (f[i]) last[i] = i;
    }
    for (int i = 2; i < N; i++) {
        if (!f[i]) continue;
        for (int j = i; j + i - 1 < N; j += i) {
            ans = max(ans, last[j + i - 1] % i);
        }
    }
    cout << ans << endl;
}
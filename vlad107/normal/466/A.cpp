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

int n, m, a, b, res = 1e9;

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i <= 1000; i++) {
        int cur = b * i + max(n - i * m, 0) * a;
        res = min(res, cur);
    }
    cout << res << endl;
}
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

const int N = 1000500;

int n, a[N];
long long sum = 0, suff[N];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % 3 != 0) {
        puts("0");
        return 0;
    }
    long long need = sum / 3;
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        suff[i] = (sum == need);
        if (i + 1 < n) {
            suff[i] += suff[i + 1];
        }
    }
    sum = a[0];
    long long res = 0;
    for (int i = 1; i + 1 < n; i++) {
        if (sum == need) {
            res += suff[i + 1];
        }
        sum += a[i];
    }
    cout << res << endl;
}
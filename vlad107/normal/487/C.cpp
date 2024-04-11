#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int N = 500500;

int n, g, used[N], a[N];

bool ok(int x, int n) {
    memset(used, 0, sizeof(used));
    int cur = 1;
    for (int i = 0; i < n - 1; i++) {
        if (used[cur]) return false;
        used[cur] = true;
        cur = (cur * 1LL * x) % n;
    }
    return true;
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    if (n == 1) {
        puts("YES\n1");
        return 0;
    }
    if (n == 4) {
        puts("YES\n1\n3\n2\n4");
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            puts("NO");
            return 0;
        }
    }   
    puts("YES");
    for (int i = 1; i < n; i++) {
        if (ok(i, n)) {
            g = i;
            break;
        }
    }
    int cur = 1;
    for (int i = 0; i < n; i++) {
        a[i] = cur;
        cur = (cur * 1LL * g) % n;
    }
    int l = 0, r = 0;
    printf("%d\n", 1);
    for (int i = 0; i < n - 2; i++) {
        if (i % 2 == 0) {
            printf("%d\n", a[(++r - l + n) % n]);
        } else {
            printf("%d\n", a[(10 * n - 1 - (r - --l)) % n]);
        }
    }
    printf("%d\n", n);                 
}
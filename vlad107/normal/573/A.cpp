#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5e5;
const int INF = 1e9 + 19;

int a[N];

int gcd(int x, int y) {
    while ((x > 0) && (y > 0)) {
        if (x > y) x %= y; else y %= x;
    }
}

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif 

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        int x = a[i];
        int c2 = 0;
        int c3 = 0;
        while (x % 2 == 0) {
            x /= 2;
            ++c2;
        }
        while (x % 3 == 0) {    
            x /= 3;
            ++c3;
        }
        a[i] = x;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
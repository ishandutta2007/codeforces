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
int n, m;
int ans[N];

int gcd(int x, int y) {
    while ((x != 0) && (y != 0)) {
        if (x > y) x %= y; else y %= x;
    }
    return x + y;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n * n);
    reverse(a, a + n * n);
    priority_queue<int> q;
    for (int i = 0; i < n * n; i++) {
        if ((!q.empty()) && (q.top() == a[i])) {
            q.pop();
            continue;
        }
        for (int j = 0; j < m; j++) {
            int x = gcd(ans[j], a[i]);
            q.push(x);
            q.push(x);
        }
        ans[m++] = a[i];
    }
    for (int i = 0; i < m; i++) printf("%d ", ans[i]);
    puts("");
}
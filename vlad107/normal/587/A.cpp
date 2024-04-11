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

const int N = 1e6 + 1000;
const int INF = 1e9 + 19;

int a[N];

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int ans = 0;
    for (int i = 0; i + 1 < N; i++) {
        if (a[i] & 1) ++ans;
        a[i + 1] +=  a[i] / 2;
    }
    cout << ans << endl;
}
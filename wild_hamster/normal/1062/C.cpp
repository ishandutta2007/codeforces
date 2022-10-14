#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <time.h>
#include <sstream>
#include <random>
#include <utility>
#define MOD 1000000007
using namespace std;
vector<int> f;
int l, a[100500], pa[100500], p2[100500];
int main() {
    //freopen("input.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    p2[0] = 1;
    for (int i = 1; i <= 100200; i++)
        p2[i] = p2[i-1]*2%MOD;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        a[i+1] = a[i] + s[i] - '0';
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        int k = a[r] - a[l-1];
        int ans = (1LL * (p2[k] - 1 + MOD) + 1LL * (p2[k] - 1) * (p2[r-l-k+1] - 1))%MOD;
        printf("%d\n", ans);
    }
    return 0;
}
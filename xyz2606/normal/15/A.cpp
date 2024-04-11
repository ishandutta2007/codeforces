#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 11111;
const double eps = 1e-8;
struct House{
    int x, wide;
}po[MAXN];


bool cmp(House p1, House p2) {
    return p1.x < p2.x;
}

int n, len;

int main() {
    scanf("%d%d", &n, &len);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &po[i].x, &po[i].wide);
    }
    sort(po + 1 , po + n + 1, cmp);
    
    int ans = 2;
    
    for (int i = 1; i < n; i++) {
        double tmp = po[i].x + po[i].wide * 1.0 / 2.0;
        double tmp2 = po[i + 1].x - po[i + 1].wide * 1.0 / 2.0;
        if (tmp + len * 1.0 < tmp2 - 0.4) ans += 2;
        else if (tmp + len * 1.0 < tmp2 + eps) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
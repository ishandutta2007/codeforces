#include <bits/stdc++.h>
using namespace std;

int intersect(int x, int y, int x2, int y2) {
    return max(0, min(y2, y) - max(x, x2) + 1);
}
int main() {
    int la, ra, ta; cin >> la >> ra >> ta;
    int lb, rb, tb; cin >> lb >> rb >> tb;
    int g = __gcd(ta, tb);
    int x = la % g, y = lb % g;
    int l1 = ra - la, l2 = rb - lb;
    int ans = intersect(x, x + l1, y, y + l2);
    ans = max(ans, intersect(x - g, x - g + l1, y, y + l2));
    ans = max(ans, intersect(x + g, x + g + l1, y, y + l2));
    cout << ans << "\n";
}
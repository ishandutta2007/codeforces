#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll dist(ll sx, ll sy, ll gx, ll gy) {
    ll dx = abs(sx - gx), dy = abs(sy - gy);
    return max(dx, dy);
}

int main() {
    ll n, x, y;
    cin >> n >> x >> y;

    cout << (dist(1, 1, x, y) <= dist(n, n, x, y) ? "White" : "Black") << endl;
    return 0;
}
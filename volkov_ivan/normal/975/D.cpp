#include <iostream>
#include <map>
 
using namespace std;

struct point{
    long long x, y;
    point() {}
    point(long long x, long long y) {
        this->x = x;
        this->y = y;
    }
    point operator + (point a) {
        return point(x + a.x, y + a.y);
    }
    point operator - (point a) {
        return point(x - a.x, y - a.y);
    }
    long long operator ^ (point a) {
        return (x * a.y - y * a.x);
    }
};

map <long long, long long> all;
map <pair <long long, long long>, long long> all2;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    long long n, a, b, x, y, vx, vy;
    cin >> n >> a >> b;
    point t(point(0, b) - point(1, a + b));
    for (int i = 0; i < n; i++) {
        cin >> x >> vx >> vy;
        point v(vx, vy);
        all2[{vx, vy}]++;
        all[v ^ t]++;
    }
    long long ans = 0;
    for (pair <long long, long long> elem : all) {
        //cout << elem.first << ' ' << elem.second << endl;
        ans += (elem.second - 1) * elem.second;
    }
    for (pair <pair <long long, long long>, long long> elem : all2) {
        ans -= (elem.second - 1) * elem.second;
    }
    cout << ans << endl;
    return 0;
    return 0;
}
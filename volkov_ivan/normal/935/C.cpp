#include <iostream>
#include <cmath>
 
using namespace std;

const long double eps = 1e-9;

class vect{
public:
    long double x, y;
    vect() {}
    vect(long double x, long double y) {
        this->x = x;
        this->y = y;
    }
    long double get_len() {
        return sqrt(x * x + y * y);
    }
    void set_len(long double new_len) {
        long double k = new_len / get_len();
        x *= k;
        y *= k;
    }
    vect operator + (vect a) {
        return vect(x + a.x, y + a.y);
    }
    vect operator - (vect a) {
        return vect(x - a.x, y - a.y);
    }
    void init() {
        cin >> x >> y;
    }
};


int main() {
    cout.precision(12);
    vect c, fafa;
    long double R;
    cin >> R;
    c.init();
    fafa.init();
    if (((fafa.x - c.x) * (fafa.x - c.x) + (fafa.y - c.y) * (fafa.y - c.y)) > R * R) {
        cout << fixed << c.x << ' ' << c.y << ' ' << R << endl;
        return 0;
    }
    if (c.x == fafa.x && c.y == fafa.y) {
        //cout << 48 << endl;
        cout << fixed << c.x << ' ' << c.y + R / 2 << ' ' << R / 2 << endl;
        return 0;
    }
    vect f = c - fafa;
    f.set_len(f.get_len() + R);
    vect ans = vect(f.x / 2, f.y / 2);
    long double r = ans.get_len();
    ans = fafa + ans;
    cout << fixed << ans.x << ' ' << ans.y << ' ' << r << endl;
    return 0;
}
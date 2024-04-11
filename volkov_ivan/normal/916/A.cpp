#include <iostream>

using namespace std;

int awake, x;

int good(int time) {
    int h = time / 60;
    int m = time % 60;
    if (h % 10 == 7 || h / 10 == 7) return 1;
    if (m % 10 == 7 || m / 10 == 7) return 1;
    return 0;
}

int check(int time) {
    for (int i = 0; i < 1500; i++) {
        if (time == awake) return i;
        time = (time + x) % 1440;
    }
    return 50000;
}

int main() {
    int ans = 50000, h, m;
    cin >> x >> h >> m;
    awake = 60 * h + m;
    for (int i = 0; i < 1440; i++) {
        if (!good(i)) continue;
        ans = min(ans, check(i));
    }
    cout << ans << endl;
    return 0;
}
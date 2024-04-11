#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, h2, a, b;
    cin >> h1 >> h2 >> a >> b;
    int count_days = 0;
    long long cur_h = h1;
    bool reached = false;
    for (int iteration = 1; iteration <= 112345; iteration++) {
        for (int hour = 14; hour < 22; hour++) {
            cur_h += a;
            if (cur_h >= 1LL * h2) {
                reached = true;
                break;
            }
        }
        if (reached) {
            break;
        }
        count_days++;
        for (int hour = -2; hour < 10; hour++) {
            cur_h -= b;
        }
        for (int hour = 10; hour < 14; hour++) {
            cur_h += a;
            if (cur_h >= 1LL * h2) {
                reached = true;
                break;
            }
        }
        if (reached) {
            break;
        }
    }

    if (!reached) {
        count_days = -1;
    }
    cout << count_days << endl;
    return 0;
}
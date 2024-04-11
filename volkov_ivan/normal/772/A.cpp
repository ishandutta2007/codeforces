#include <iostream>

using namespace std;

const int MAX_N = 1e5;
int a[MAX_N], b[MAX_N];

bool check(int n, int p, long double t) {
    long double summ = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] - a[i] * t <= 0) {
            summ += (a[i] * t - b[i]) / p;
        }
    }
    return (summ < t);
}

int main() {
    cout.precision(6);
    ios_base :: sync_with_stdio(0);
    long long n, p;
    cin >> n >> p;
    long long s_a = 0, s_b = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        s_a += a[i];
        s_b += b[i];
    }
    if (p >= s_a) {
        cout << "-1" << endl;
        return 0;
    }
    long double l = 0, r = 1e18, m;
    for (int i = 0; i < 100; i++) {
        m = (l + r) / 2;
        if (check(n, p, m)) l = m;
        else r = m;
    }
    cout << fixed << l << endl;
    return 0;
}
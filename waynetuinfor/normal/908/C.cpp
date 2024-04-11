#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int maxn = 1000 + 10;
int x[maxn];
double ans[maxn];

double dist(double a, double b, double x, double y) {
    return sqrt((a - x) * (a - x) + (b - y) * (b - y));
}

int32_t main() {
    int n, r; cin >> n >> r;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) {
        ans[i] = r;
        for (int j = 0; j < i; ++j) {
            ans[i] = max(ans[i], ans[j] + sqrt(4 * r * r - abs(x[i] - x[j]) * abs(x[i] - x[j])));
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(20) << ans[i] << ' '; 
    }
    cout << endl;
}
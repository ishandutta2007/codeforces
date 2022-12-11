#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    long long diff[n], summ = 0, a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        diff[i] = a - b;
        summ += a;
    }
    sort(diff, diff + n, greater <long long>());
    if (summ <= m) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        summ -= diff[i];
        if (summ <= m) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
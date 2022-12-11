#include <iostream>

using namespace std;

const int INF = 1e7;

int main() {
    long long n, k1, k2;
    cin >> n >> k1 >> k2;
    long long a[n], b[n], arr[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        arr[i] = abs(a[i] - b[i]);
    }
    int maxi, pos;
    //cout << k1 << ' ' << k2 << ' ' << k1 + k2 << endl;
    for (int i = 0; i < k1 + k2; i++) {
        maxi = -INF;
        for (int j = 0; j < n; j++) {
            if (arr[j] > maxi) {
                maxi = arr[j];
                pos = j;
            }
        }
        if (arr[pos] > 0) arr[pos]--;
        else arr[pos]++;
    }
    //for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    //cout << endl;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i] * arr[i];
        //cout << arr[i] << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
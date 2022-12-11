#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 1, in_path = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] > k) {
            cout << -1 << endl;
            return 0;
        }
        if (in_path + (arr[i] - arr[i - 1]) > k) {
            ans++;
            in_path = arr[i] - arr[i - 1];
        } else {
            in_path += arr[i] - arr[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
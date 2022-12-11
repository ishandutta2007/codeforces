#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    pair <int, int> arr[n];
    bool is_sep[n];
    for (int i = 0; i < n; i++) {
        is_sep[i] = 0;
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        is_sep[arr[n - i - 1].second] = 1;
        ans += arr[n - i - 1].first;
    }
    cout << ans << endl;
    int cnt = 0, cnt2 = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        if (is_sep[i] && cnt2 != k - 1) {
            cnt2++;
            cout << cnt << ' ';
            cnt = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
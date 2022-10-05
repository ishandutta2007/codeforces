//
// Created by Danny Mittal on 7/1/19.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int all[200000];

int main() {
    int t, n, k;
    int* arr = all;
    memset(all, 0, 200000 * sizeof(int));
    cin >> t;
    for (int c = 0; c < t; c++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            arr[k - 1]++;
        }
        sort(arr, arr + n);
        int res = 0, prev = n + 1;
        for (int i = n - 1; i >= 0 && min(prev - 1, arr[i]) > 0; i--) {
            prev = min(prev - 1, arr[i]);
            res += prev;
        }
        cout << res << '\n';
        arr += n;
    }
    cout << flush;
}
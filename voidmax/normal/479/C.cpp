#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

int n, a, b, L = -1, R = 1e9 + 1;
vector <pair <int, int> > arr;

bool ans(int a, int b) {
    if (a >= arr[b].first) {
        return true;
    }
    if (b > 0 && a >= arr[b].second) {
        return ans(arr[b].second, b - 1);
    }
    else if (b == 0 && a >= arr[b].second) {
        return true;
    }
    return false;
}

main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end());
    if ((arr[n - 1].second < arr[n - 1].first) && ans(arr[n - 1].second, n - 1)) {
        cout << arr[n - 1].second;
    }
    else {
        cout << arr[n - 1].first;
    }
}
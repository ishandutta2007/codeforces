#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

vector<vector<int>> adj;

long long get_sum(int i, int j) {
    cout << "and " << i + 1 << " " << j + 1 << "\n";
    cout.flush();
    long long x; cin >> x;
    cout << "or " << i + 1 << " " << j + 1 << "\n";
    cout.flush();
    long long y; cin >> y;
    return x + y;
}

int main() {
    int n, k; cin >> n >> k;
    vector<long long> a(n);
    long long x = get_sum(0, 1), y = get_sum(1, 2), z = get_sum(0, 2);
    a[0] = (x + y + z) / 2 - y;
    a[1] = (x + y + z) / 2 - z;
    a[2] = (x + y + z) / 2 - x;
    for (int i = 3; i < n; i++) {
        a[i] = get_sum(i - 1, i) - a[i - 1];
    }
    sort(a.begin(), a.end());
    cout << "finish " << a[k - 1] << "\n";
    cout.flush();
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long n, k; cin >> n >> k;
        long long time = 0;
        long long num = 1;
        while (num < k) {
            num *= 2;
            ++time;
        }
        if (num >= n) {
            cout << time << "\n";
        } else {
            time += (n - num + k - 1) / k;
            cout << time << "\n";
        }
    }
}
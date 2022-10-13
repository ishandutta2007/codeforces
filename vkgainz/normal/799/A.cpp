#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int n, t, k, d; cin >> n >> t >> k >> d;
    int num = (n + k - 1) / k * t;
    int numOven = 0;
    array<int, 2> gt = {0, d};
    int left = (n + k - 1) / k;
    while (left > 0) {
        if (gt[0] < gt[1]) {
            gt[0] += t;
        } else {
            gt[1] += t;
        }
        --left;
    }
    if (max(gt[0], gt[1]) < num) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}
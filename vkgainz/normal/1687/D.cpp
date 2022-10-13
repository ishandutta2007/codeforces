#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;

vector<int> le(2000000), ge(2000000);
int n;

int get_le(int sq, long long lookup) {
    long long mx = lookup - sq * 1LL * sq;
    if (mx >= 2000000) {
        return n - 1;
    } else {
        return le[mx];
    }
}

int get_ge(int sq, long long lookup) {
    long long mn = lookup - sq * 1LL * sq;
    //check this!
    if (mn >= 2000000) {
        return n - 1;
    } else {
        return ge[mn];
    }
}

int main() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0; i < 2000000; i++) {
        while (j < n && a[j] - a[0] <= i) {
            ++j;
        }
        le[i] = j - 1;
    }
    j = n - 1;
    for (int i = 2000000 - 1; i >= 0; i--) {
        while (j >= 0 && a[j] - a[0] >= i) {
            --j;
        }
        ge[i] = j + 1;
    }
    long long ans = 5e12;
    for (int match = 1; match <= 2000000; match++) {
        if (match * 1LL * (match + 1) < a[0]) continue;
        int curr = match;
        long long up = 1e12, down = 0;
        //min to remove out of interval
        long long k = match * 1LL * match - a[0];
        //max to get in interval
        while (true) {
            if (curr * 1LL * curr - match * 1LL * match >= 2e6) break;
            //[curr * curr, curr * curr + curr]
            //[curr * curr + curr + 1, (curr + 1) * (curr + 1) - 1]
            int idx_le = get_le(match, curr * 1LL * curr + curr);
            //make sure >= curr * 1LL * curr
            int idx_ge = get_ge(match, curr * 1LL * curr + curr + 1);
            //make sure < (curr + 1) * 1LL * (curr + 1)
            if (a[idx_le] + k >= curr * 1LL * curr
                    && a[idx_le] + k <= curr * 1LL * (curr + 1)) {
                up = min(up, curr * 1LL * (curr + 1) - (a[idx_le] + k));
            }
            if (idx_ge < n && a[idx_ge] + k < (curr + 1) * 1LL * (curr + 1) 
                    && a[idx_ge] + k > curr * 1LL * (curr + 1)) {
                down = max(down, (curr + 1) * 1LL * (curr + 1)
                        - (a[idx_ge] + k));
            }
            ++curr;
        }
        if (down <= up) {
            ans = min(ans, k + down);
        }
    }
    ans = max(ans, 0LL);
    cout << ans << "\n";
}
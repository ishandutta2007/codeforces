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

vector<int> get_ge(vector<long long> &nums, int n) {
    vector<int> stack;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && nums[stack.back()] <= nums[i]) {
            stack.pop_back();
        }
        if (stack.empty()) {
            ans[i] = n;
        } else {
            ans[i] = stack.back();
        }
        stack.push_back(i);
    }
    return ans;
}

bool work(vector<int> &a, int n) {
    vector<long long> age(n), pge(n);
    for (int i = 0; i < n; i++) {
        age[i] = a[i];
        if (i == 0) pge[i] = a[i];
        else {
            pge[i] = pge[i - 1] + a[i];
        }
    }
    vector<int> age_i = get_ge(age, n);
    vector<int> pge_i = get_ge(pge, n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (age_i[i] == n) {
            if (pge_i[i] < n) {
                ans = 1;
                break;
            }
        } else {
            if (pge_i[i] < age_i[i]) {
                ans = 1;
                break;
            }
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = work(a, n);
    reverse(a.begin(), a.end());
    ans = ans || work(a, n);
    if (!ans) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
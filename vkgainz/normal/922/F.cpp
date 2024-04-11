#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define all(c) ((c).begin()), ((c).end())

int num[300001];

int main() {
    int n, k; cin >> n >> k;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += n / i;
    }
    tot -= n;
    if (tot < k) {
        cout << "No" << "\n";
        return 0;
    }
    vector<int> ans;
    for (int i = 1; i <= n / 2; i++) {
        if (k < num[i]) {
            break;
        } else {
            k -= num[i];
            ans.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                ++num[j];
            }
        }
    }
    vector<pair<int, int>> in;
    for (int j = n / 2 + 1; j <= n; j++) {
        in.push_back({num[j], j});
    }
    sort(in.begin(), in.end());
    while (in.size()) {
        if (k >= in.back().first) {
            k -= in.back().first;
            ans.push_back(in.back().second);
        }
        in.pop_back();
    }
    sort(ans.begin(), ans.end());
    cout << "Yes" << "\n";
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}
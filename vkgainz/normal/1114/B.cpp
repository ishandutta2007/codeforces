#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <array>
 
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ord[i] = {a[i], i};
    }
    sort(ord.begin(), ord.end());
    reverse(ord.begin(), ord.end());
    vector<bool> mark(n);
    for (int i = 0; i < m * k; i++) {
        mark[ord[i].second] = 1;
    }
    int curr = 0;
    vector<int> ans;
    long long ret = 0LL;
    for (int i = 0; i < n; i++) {
        curr += mark[i];
        ret += a[i] * mark[i];
        if (curr == m) {
            ans.push_back(i);
            curr = 0;
        }
    }
    cout << ret << "\n";
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
}
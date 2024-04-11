#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.length();
    int ans = 1e9;
    for (int i = 0; i < 26; i++) {
        vector<int> pos;
        pos.push_back(-1);
        for (int j = 0; j < n; j++) {
            if (s[j] - 'a' == i) {
                pos.push_back(j);
            }
        }
        pos.push_back(n);
        int k = 0;
        for (int i = 0; i < pos.size() - 1; i++) {
            k = max(k, pos[i + 1] - pos[i]);
        }
        ans = min(ans, k);
    }
    cout << ans << "\n";
}
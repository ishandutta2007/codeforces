#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>
#include <type_traits>
#include <exception>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;        
        string s, t;
        cin >> s >> t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int cur = -1, cnt = 0;
        int i = 0, j = 0;
        string res;
        while ((i < s.size()) && (j < t.size())) {
            if (cnt == k) {
                if (cur == 0) {
                    res += t[j];
                    ++j;
                    cur = 1;
                } else {
                    res += s[i];
                    ++i;
                    cur = 0;
                }

                cnt = 1;
            } else {
                if (s[i] < t[j]) {
                    res += s[i];
                    ++i;
                    if (cur == 0) {
                        ++cnt;
                    } else {
                        cur = 0; cnt = 1;
                    }
                } else {
                    res += t[j];
                    ++j;
                    if (cur == 1) {
                        ++cnt;
                    } else {
                        cur = 1; cnt = 1;
                    }
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
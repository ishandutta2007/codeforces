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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];        
        if (n == 1) {
            cout << "-1\n";
        } else {
            vector<bool> used(n + 1);
            for (int i = 0; i < n - 2; i++) {
                for (int j = 1; j <= n; j++) {
                    if ((!used[j]) && (j != a[i])) {
                        used[j] = true;
                        cout << j << " ";
                        break;
                    }
                }
            }
            vector<int> v;
            for (int i = 1; i <= n; i++) {
                if (!used[i]) v.push_back(i);
            }
            if ((v[0] == a[n - 2]) || (v[1] == a[n - 1])) {
                swap(v[0], v[1]);
            }
            cout << v[0] << " " << v[1] << "\n";
        }
    }
    return 0;
}
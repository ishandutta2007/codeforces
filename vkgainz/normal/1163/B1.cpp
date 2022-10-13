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
    int n; cin >> n;
    vector<int> u(n);
    for (int i = 0; i < n; i++) 
        cin >> u[i], --u[i];
    vector<int> freq(10);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ++freq[u[i]];
        int sum = 0;
        int mx = 0;
        int appear = 0;
        int freq_mx = 0;
        int ones = 0;
        for (int j = 0; j < 10; j++) {
            sum += freq[j];
            if (freq[j] > mx) {
                mx = freq[j];
                freq_mx = 1;
            }  else if (freq[j] == mx) {
                ++freq_mx;
            }
            ones += freq[j] == 1;
            mx = max(mx, freq[j]);
            appear += freq[j] > 0;
        }
        if (appear == 1) {
            ans = max(ans, i + 1);
        }
        if (ones == appear) {
            ans = max(ans, i + 1);
        }
        if (freq_mx == 1 && (mx - 1) * appear == sum - 1) {
            ans = max(ans, i + 1);
        } else {
            int mn = 200000;
            int freq_mn = 0;
            for (int j = 0; j < 10; j++) {
                if (freq[j] > 0) {
                    if (freq[j] < mn) {
                        mn = freq[j];
                        freq_mn = 1;
                    } else if (freq[j] == mn) {
                        ++freq_mn;
                    }
                }
            }
            if (mn == 1 && freq_mn == 1) {
                int new_mn = 200000, new_mx = 0;
                for (int j = 0; j < 10; j++) {
                    if (freq[j] > 0 && freq[j] != mn) {
                        new_mn = min(new_mn, freq[j]);
                        new_mx = max(new_mx, freq[j]);
                    }
                }
                if (new_mn == new_mx) {
                    ans = max(ans, i + 1);
                }
            }

        }
    }
    cout << ans << "\n";
}
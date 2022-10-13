#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        if (n == 1) {
            cout << s.substr(0, 1) + s.substr(0, 1) << "\n";
        } else {
            if (s[0] == s[1]) {
                cout << s.substr(0, 1) + s.substr(0, 1) << "\n";
            } else {
                bool found = false;
                for (int i = 0; i < n - 1; i++) {
                    if (s[i] < s[i + 1]) {
                        found = true;
                        string ans = s.substr(0, i + 1);
                        cout << ans;
                        reverse(ans.begin(), ans.end());
                        cout << ans << "\n";
                        break;
                    }
                }
                if (!found) {
                    cout << s;
                    reverse(s.begin(), s.end());
                    cout << s << "\n";
                }
            }
        }
    }
}
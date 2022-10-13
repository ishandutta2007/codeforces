#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string n; cin >> n;
        int ans = 0;
        for (int j = n.size() - 1; j >= 0; j--) {
            bool work = false;
            for (int i = n.size(); i > j; i--) {
                int sum = (n[j] - '0') * 10 + (n[i] - '0');
                if (sum % 25 == 0) {
                    work = true;
                }
            }
            if (work) {
                ans = n.size() - j - 2;
                break;
            }
        }
        cout << ans << "\n";
    }
}
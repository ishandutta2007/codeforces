#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i] - '0';
        }
        if (sum == n) {
            cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
        }
        else {
            int zer = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0')
                    zer = i + 1;
            }
            if (zer > n / 2) {
                cout << 1 << " " << zer << " " << 1 << " " << zer - 1 << "\n";
            }
            else {
                cout << zer << " " << n << " " << zer + 1 << " " << n << "\n";
            }
        }
    }
}
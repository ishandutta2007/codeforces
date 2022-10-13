#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        bool comp = false;
        for (int i = 2; i <= min(1000, sum - 1); i++) {
            if (sum % i == 0) {
                comp = true;
            }
        }
        if (comp) {
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        } else {
            int mnOdd = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] % 2) {
                    if (mnOdd == -1 || a[i] < a[mnOdd])
                        mnOdd = i;
                }
            }
            cout << n - 1 << "\n";
            for (int i = 0; i < n; i++) {  
                if (i != mnOdd)
                    cout << i + 1 << " ";
            }
            cout << "\n";
        }
    }
}
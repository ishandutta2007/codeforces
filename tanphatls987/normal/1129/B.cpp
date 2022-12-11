#include <bits/stdc++.h>

using namespace std;

const int maxv = 1000000;

bool solve(int l1, int l2, int k) {
    int rem = k + (l1 + l2);
    if (rem < 0) return 0;
    if (rem % l1 == 0) {
        int x = rem / l1; 
        if (l2 * maxv < x) return 0;
        cout << l1 + l2 << '\n';
        for(int i = 1; i <= l1; i++) cout << -(i == l1) << " ";
        for(int i = 1; i <= l2; i++) {
            int use = min(maxv, rem);
            rem -= use;
            cout << use << " ";
        }
        return 1;
    }
    return 0;
}
int main() {
    int k;
    cin >> k;
    for(int l1 = 1; l1 <= 2000; l1++)
        for(int l2 = 1; l1 + l2 <= 2000; l2++) {
            if (solve(l1, l2, k)) return 0;
        }
    cout << "-1";
}
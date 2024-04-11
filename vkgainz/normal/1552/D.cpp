#include <bits/stdc++.h>
using namespace std;
 
bool recurse(int sum, int i, vector<int> &a, bool taken) {
    if(sum == 0 and taken) {
        return true;
    }
    if(i == (int) a.size()) {
        return sum == 0 and taken;
    }
    return recurse(sum + a[i], i + 1, a, true) or recurse(sum - a[i], i + 1, a, true) or recurse(sum, i + 1, a, taken);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(recurse(0, 0, a, 0)) {
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";
    }
}
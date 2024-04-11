#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        vector<int> sA(n), sB(n);
        for (int i = 0; i < n; i++) {
            if (i > 0) sA[i] = sA[i - 1];
            if (a[i] == '0') ++sA[i];
            else --sA[i];
            if (i > 0) sB[i] = sB[i - 1];
            if (b[i] == '0') ++sB[i];
            else --sB[i];
        }
        bool flip = false;
        bool work = true;
        for (int i = n - 1; i >= 0; i--) {
            char curr = a[i];
            if (flip) {
                if (curr == '0') curr = '1';
                else curr = '0';
            }
            if (curr != b[i]) {
                if (sA[i] == 0)
                    flip = !flip;
                else {
                    work = false;
                    break;
                }
            }
        }
        if (!work) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}
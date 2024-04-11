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
        string ans = "";
        vector<string> in(n - 2);
        for (int i = 0; i < n - 2; i++) {
            cin >> in[i];
        }
        int spl = -1;
        for (int i = 0; i < n - 3; i++) {
            if (in[i][1] != in[i + 1][0]) {
                spl = i;
                break;
            }
        }
        for (int i = 0; i <= spl; i++) {
            if (i == 0) {
                ans += in[i];
            } else {
                ans += in[i][1];
            }
        }
        for (int i = spl + 1; i < n - 2; i++) {
            if (i == spl + 1) {
                ans += in[i];
            } else {
                ans += in[i][1];
            }
        }
        if (spl == -1) {
            ans += 'a';
        }
        cout << ans << "\n";
    }
}
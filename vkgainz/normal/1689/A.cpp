#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int curr = 0, num = 0;
        string a, b; cin >> a >> b;
        int i = 0, j = 0;
        string ans = "";
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while (i < a.length() && j < b.length()) {
            if (a[i] < b[j]) {
                if (curr == 0) {
                    if (num == k) {
                        ans += b[j++];
                        curr = 1;
                        num = 1;
                    } else {
                        ans += a[i++];
                        ++num;
                    }
                } else {
                    curr = 0;
                    ans += a[i++];
                    num = 1;
                }
            } else {
                if (curr == 1) {
                    if (num == k) {
                        ans += a[i++];
                        curr = 0;
                        num = 1;
                    } else {
                        ans += b[j++];
                        ++num;
                    }
                } else {
                    curr = 1;
                    ans += b[j++];
                    num = 1;
                }
            }
        }
        cout << ans << "\n";
    }
}
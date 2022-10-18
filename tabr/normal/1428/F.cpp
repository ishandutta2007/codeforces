#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    long long sum = 0;
    vector<int> h(n, -1);
    int id = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            id++;
            sum += i - h[id];
        } else {
            for (int j = 0; j <= id; j++) {
                h[j] = i - j - 1;
            }
            id = -1;
        }
        ans += sum;
    }
    cout << ans << '\n';
    return 0;
}
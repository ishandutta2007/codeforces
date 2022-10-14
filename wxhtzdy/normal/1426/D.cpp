#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    long long sum = 0;
    set<long long> s;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (s.find(sum) != s.end()) {
            ans++;
            s.clear();
            s.insert(0);
            sum = a[i];
        }
        s.insert(sum);
    }
    cout << ans << '\n';
    return 0;
}
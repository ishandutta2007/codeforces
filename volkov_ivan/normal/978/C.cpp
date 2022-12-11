#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    long long a[n];
    pair <long long, int> b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    pair <int, long long> ans[m];
    sort(b, b + m);
    long long s = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && b[j].first <= s + a[i]) {
            ans[b[j].second] = {i + 1, b[j].first - s};
            j++;
        }
        s += a[i];
    }
    for (int i = 0; i < m; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}
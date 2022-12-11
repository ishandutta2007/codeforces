#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    long long hp[n], dmg[n];
    bool used[n];
    vector <pair <long long, int>> arr;
    for (int i = 0; i < n; i++) {
        cin >> hp[i] >> dmg[i];
        used[i] = 0;
        if (hp[i] > dmg[i]) {
            arr.push_back({hp[i] - dmg[i], i});
        }
    }
    long long last = 0, s1 = 0, s2 = 0;
    sort(arr.begin(), arr.end(), greater<pair <long long, int>>());
    for (int i = 0; i < min(b, (int) arr.size()); i++) {
        s1 += arr[i].first;
        if (i != b - 1) s2 += arr[i].first;
        used[arr[i].second] = 1;
    }
    for (int i = 0; i < n; i++) {
        s1 += dmg[i];
        s2 += dmg[i];
    }
    //cout << arr.size() << ' ' << s1 << ' ' << s2 << endl;
    //if ((int) arr.size() > b) last = arr[b].first;
    long long ans = s1;
    for (int i = 0; i < n; i++) {
        if (b == 0) break;
        if (used[i]) {
            ans = max(ans, s1 + hp[i] * (1ll << a) - hp[i]);
        } else {
            ans = max(ans, s2 + hp[i] * (1ll << a) - dmg[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
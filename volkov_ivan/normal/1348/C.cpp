#include <bits/stdc++.h>

using namespace std;

const int K = 256;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt[K];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    sort(s.begin(), s.end());
    string res = "";
    int mini = 0;
    while (cnt[mini] == 0) mini++;
    if (cnt[mini] < k) {
        cout << s[k - 1] << "\n";
        return;
    }
    if (cnt[mini] == n) {
        int len = (cnt[mini] + k - 1) / k;
        for (int j = 0; j < len; j++) cout << s[0];
        cout << "\n";
        return;
    }
    int mem = cnt[mini];
    bool flag = 0;
    for (int j = 0; j < cnt[mini] - (k - 1); j++) cout << s[0];
    for (int i = mini + 1; i < K; i++) {
        if (cnt[i] == 0) continue;
        if (!flag && mem == k && mem + cnt[i] == n) {
            int len = (cnt[i] + k - 1) / k;
            for (int j = 0; j < len; j++) {
                char x = 'a' + i;
                cout << x;
            }
            cout << "\n";
            return;
        }
        for (int j = 0; j < cnt[i]; j++) {
            char x = 'a' + i;
            cout << x;
        }
        flag = 1;
    }
    cout << "\n";
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}
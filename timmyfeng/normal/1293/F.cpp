#include <bits/stdc++.h>
using namespace std;

int paths[5001][5001];
int ct[5001], top[5001], freq[5001];

int main() {
    for (int i = 2; i <= 5000; i++) {
        for (int j = 2; j <= 5000; j++) {
            paths[i][j] = paths[i-1][j];
        }
        int tmp = i;
        for (int j = 2; j <= sqrt(tmp); j++) {
            while (tmp > 0 && tmp % j == 0) {
                tmp /= j;
                paths[i][j]++;
            }
        }
        if (tmp > 1) paths[i][tmp]++;
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        ct[k]++;
    }

    long long sol = 0;
    fill(top, top + 5001, 1);
    for (int i = 1; i <= 5000; i++) {
        if (!ct[i]) continue;
        for (int j = 1; j <= 5000; j++) {
            sol += 1LL * paths[i][j] * ct[i];
            if (paths[i][j]) top[i] = j;
        }
    }

    while (true) {
        memset(freq, 0, sizeof freq);
        for (int i = 1; i <= 5000; i++) {
            if (!ct[i]) continue;
            freq[top[i]] += ct[i];
        }
        int most = max_element(freq, freq + 5001) - freq;
        if (freq[most] * 2 <= n || most == 1) break;

        sol -= freq[most];
        sol += n - freq[most];
        for (int i = 1; i <= 5000; i++) {
            if (top[i] != most) {
                top[i] = 1;
            }
            if (top[i] == 1) continue;
            paths[i][top[i]]--;
            while (top[i] > 1 && paths[i][top[i]] == 0) {
                top[i]--;
            }
        }
    }
    cout << sol << "\n";
}
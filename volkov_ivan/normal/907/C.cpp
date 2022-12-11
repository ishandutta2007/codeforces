#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0, cnt, last;
    char c, now, secret;
    bool imposs[256], know = 0, fnd;
    for (int i = 0; i < 256; i++) {
        imposs[i] = 0;
    }
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '.') {
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                imposs[s[j]] = 1;
            }
            cnt = 0;
            for (char j = 'a'; j <= 'z'; j++) {
                if (!imposs[j]) {
                    cnt++;
                    last = j;
                }
            }
            if (cnt == 1) {
                secret = last;
                know = 1;
            }
        }
        if (c == '!') {
            cin >> s;
            if (know) {
                ans++;
                continue;
            }
            cnt = 0;
            for (char j = 'a'; j <= 'z'; j++) {
                fnd = 0;
                for (int k = 0; k < s.length(); k++) {
                    if (s[k] == j) {
                        fnd = 1;
                        break;
                    }
                }
                if (!fnd) {
                    imposs[j] = 1;
                }
                if (!imposs[j]) {
                    last = j;
                    cnt++;
                }
            }
            if (cnt == 1) {
                secret = last;
                know = 1;
            }
        }
        if (c == '?') {
            cin >> now;
            if (i == n - 1) {
                continue;
            }
            if (know) {
                ans++;
                continue;
            }
            imposs[now] = 1;
            cnt = 0;
            for (char j = 'a'; j <= 'z'; j++) {
                if (!imposs[j]) {
                    cnt++;
                    last = j;
                }
            }
            if (cnt == 1) {
                secret = last;
                know = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
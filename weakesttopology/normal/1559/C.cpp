#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N + 1);
        int s = -1;
        for (int i = 1; i <= N; ++i) {
            cin >> a[i];
            if (a[i] == 1 && a[i - 1] == 0) {
                s = i;
            }
        }
        if (s == -1 && a[N] == 1) {
            cout << "-1\n";
            continue;
        }
        vector<int> I;
        if (a[N] == 0) {
            for (int i = 1; i <= N + 1; ++i) {
                I.push_back(i);
            }
        } else {
            for (int i = 1; i < s; ++i) {
                I.push_back(i);
            }
            I.push_back(N + 1);
            for (int i = s; i <= N; ++i) {
                I.push_back(i);
            }
        }
        for (int i = 0; i < N + 1; ++i) {
            cout << I[i] << "\n "[i < N];
        }
    }
    exit(0);
}
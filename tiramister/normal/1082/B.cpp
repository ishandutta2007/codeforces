#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int G = 0;
    for (char c : S) {
        G += (c == 'G');
    }

    int l[N + 2], r[N + 2];
    l[0] = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'G') {
            l[i + 1] = l[i] + 1;
        } else {
            l[i + 1] = 0;
        }
    }

    r[N + 1] = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (S[i] == 'G') {
            r[i + 1] = r[i + 2] + 1;
        } else {
            r[i + 1] = 0;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, l[i - 1] + r[i + 1]);
        if (l[i - 1] + r[i + 1] < G) {
            ans = max(ans, l[i - 1] + r[i + 1] + 1);
        }
    }

    cout << ans << endl;
    return 0;
}
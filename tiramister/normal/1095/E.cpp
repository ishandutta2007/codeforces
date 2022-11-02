#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int h = 0, mi = 0;
    for (char c : S) {
        h += (c == '(' ? 1 : -1);
        mi = min(mi, h);
    }

    int ans = 0;
    if (h == 2 && mi >= 0) {
        h = mi = 0;
        for (int i = N - 1; i >= 0; --i) {
            h += (S[i] == ')' ? 1 : -1);
            mi = min(h, mi);

            if (S[i] == '(') ++ans;
            if (mi <= -1) break;
        }
    } else if (h == -2 && mi >= -2) {
        h = mi = 0;
        for (int i = 0; i < N; ++i) {
            h += (S[i] == '(' ? 1 : -1);
            mi = min(h, mi);

            if (S[i] == ')') ++ans;
            if (mi <= -1) break;
        }
    }

    cout << ans << endl;
    return 0;
}
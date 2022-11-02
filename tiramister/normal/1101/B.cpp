#include <iostream>
#include <string>

using namespace std;

const string fore = "[:", back = "]:";

int main() {
    string S;
    cin >> S;

    string T;
    int idx = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (idx == 2) {
            T.push_back(S[i]);
            continue;
        }
        if (S[i] == fore[idx]) ++idx;
    }

    if (idx < 2) {
        cout << -1 << endl;
        return 0;
    }

    idx = 0;
    int ans = 4;
    for (int i = T.length() - 1; i >= 0; --i) {
        if (idx == 2) {
            ans += (T[i] == '|');
            continue;
        }
        if (T[i] == back[idx]) ++idx;
    }

    cout << (idx < 2 ? -1 : ans) << endl;
    return 0;
}
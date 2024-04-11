#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> S[N];
    string s[N * 2 - 2];
    for (int i = 0; i < N * 2 - 2; ++i) {
        cin >> s[i];
        S[s[i].length()].push_back(s[i]);
    }

    while (true) {
        bool judge = true;

        for (int k = 1; k <= N - 2; ++k) {
            if (S[k][0] != S[N - 1][0].substr(0, k)) {
                if (S[k][1] == S[N - 1][0].substr(0, k)) {
                    swap(S[k][0], S[k][1]);
                } else {
                    judge = false;
                    break;
                }
            }

            if (S[k][1] != S[N - 1][1].substr(N - k - 1)) {
                judge = false;
                break;
            }
        }

        if (judge) break;
        swap(S[N - 1][0], S[N - 1][1]);
    }

    for (int i = 0; i < N * 2 - 2; ++i) {
        if (s[i] == S[s[i].length()][0]) {
            cout << 'P';
            S[s[i].length()][0] = "$";
        } else {
            cout << 'S';
        }
    }

    cout << endl;
    return 0;
}
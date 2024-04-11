#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.length();

    bool judge = false;
    for (int i = 1; i < N - i - 1; ++i) {
        if (S[i] != S[i - 1]) judge = true;
    }

    if (!judge) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 1; i < N - 1; ++i) {
        string cut = S.substr(i) + S.substr(0, i);
        if (cut == S) continue;

        string rev = cut;
        reverse(rev.begin(), rev.end());
        if (cut == rev) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 2 << endl;
    return 0;
}
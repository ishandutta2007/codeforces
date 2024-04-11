#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kind(char c) {
    if (islower(c)) return 0;
    if (isupper(c)) return 1;
    return 2;
}

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        string S;
        cin >> S;
        int cnt[3] = {0, 0, 0};
        for (char c : S) ++cnt[kind(c)];

        int itr = 0;
        for (char& c : S) {
            while (itr < 3 && cnt[itr] > 0) ++itr;
            if (itr == 3) break;
            if (cnt[kind(c)] > 1) {
                --cnt[kind(c)];
                c = "aA1"[itr];
                ++cnt[itr];
            }
        }

        cout << S << endl;
    }
    return 0;
}
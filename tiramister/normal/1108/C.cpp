#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    string RGB = "RGB";
    string best = RGB;
    int mincost = N + 1;

    for (int q = 0; q < 6; ++q) {
        int cost = 0;
        for (int i = 0; i < N; ++i) {
            if (S[i] != RGB[i % 3]) ++cost;
        }

        if (cost < mincost) {
            best = RGB;
            mincost = cost;
        }
        next_permutation(RGB.begin(), RGB.end());
    }

    cout << mincost << endl;
    for (int i = 0; i < N; ++i) {
        cout << best[i % 3];
    }
    cout << endl;
    return 0;
}
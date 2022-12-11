#include <bits/stdc++.h>

using namespace std;

vector<int> read(int n) {
    auto v = vector<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    return v;
}

string solve(const vector<int> &v) {
    int total_xor = 0;
    for (auto &&e : v) {
        total_xor ^= e;
    }
    int game_bit = 0;
    for (int i = 30; i >= 0; i--) {
        if (total_xor & (1 << i)) {
            game_bit = i;
            break;
        }
    }
    int ones = 0, zeros = 0;
    for (auto &&e : v) {
        if (e & (1 << game_bit)) {
            ones++;
        } else {
            zeros++;
        }
    }
    if (total_xor == 0) {
        return "DRAW";
    } else if (ones % 4 == 1 || zeros % 2 == 1) {
        return "WIN";
    } else {
        return "LOSE";
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        auto values = read(n);
        cout << solve(values) << endl;
    }
    return 0;
}
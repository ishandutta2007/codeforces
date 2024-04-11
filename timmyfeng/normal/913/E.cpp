#include <bits/stdc++.h>
using namespace std;

const int N = 8;

string ans[1 << N], wrap[1 << N];
bool delta;

void set_min(string &a, string b) {
    if (a.size() > b.size() || (a.size() == b.size() && a > b)) {
        delta = true;
        a = b;
    }
}

void update(int i, string s) {
    int d = 0;
    bool w = true;
    for (auto c : s) {
        if (c == '(') {
            ++d;
        } else if (c == ')') {
            --d;
        } else if (c == '|' && d == 0) {
            w = false;
        }
    }

    set_min(ans[i], s);
    if (w) {
        set_min(wrap[i], s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(ans, ans + (1 << N), string(128, 0));
    fill(wrap, wrap + (1 << N), string(128, 0));

    update(0b11110000, "x"), update(0b00001111, "!x");
    update(0b11001100, "y"), update(0b00110011, "!y");
    update(0b10101010, "z"), update(0b01010101, "!z");

    delta = true;
    while (delta) {
        delta = false;
        for (int i = 0; i < (1 << N); ++i) {
            update(i, "(" + ans[i] + ")");
            update(i ^ ((1 << N) - 1), "!(" + ans[i] + ")");
            for (int j = 0; j < (1 << N); ++j) {
                update(i | j, ans[i] + "|" + ans[j]);
                update(i & j, wrap[i] + "&" + wrap[j]);
            }
        }
    }

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        int f = 0;
        for (int i = 0; i < N; ++i) {
            f |= (s[i] == '1') << i;
        }
        cout << ans[f] << "\n";
    }
}
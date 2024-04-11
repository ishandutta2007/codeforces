#include <bits/stdc++.h>

using namespace std;

// Is Alice win?
// dp[odd][even][is_alice_turn?][is_sum_odd?]
int dp[105][105][2][2];

bool alice_win(int odd, int even, bool is_alice_turn, bool is_sum_odd) {
    if (odd == 0 && even == 0) return !is_sum_odd;
    int &d = dp[odd][even][is_alice_turn][is_sum_odd];
    if (d != 0) return d == 1;
    if (is_alice_turn) {
        bool win = false;
        if (odd > 0 && alice_win(odd - 1, even, false, !is_sum_odd)) win = true;
        else if (even > 0 && alice_win(odd, even - 1, false, is_sum_odd)) win = true;
        d = win ? 1 : -1;
        return win;
    }
    else {
        bool win = false;
        if (odd > 0 && !alice_win(odd - 1, even, true, is_sum_odd)) win = true;
        else if (even > 0 && !alice_win(odd, even - 1, true, is_sum_odd)) win = true;
        d = win ? -1 : 1;
        return !win;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int cnt[2] = {};
        while (n--) {
            int x;
            cin >> x;
            ++cnt[x & 1];
        }
        printf(alice_win(cnt[1], cnt[0], true, false) ? "Alice\n" : "Bob\n");
    }
    return 0;
}
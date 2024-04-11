#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt[500010];
    fill(cnt, cnt + 500010, 0);

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;

        int h = 0, mi = 0;
        for (char c : S) {
            h += (c == '(' ? 1 : -1);
            mi = min(mi, h);
        }

        if (h < 0) mi -= h;
        if (mi < 0) continue;

        if (h == 0) {
            cnt[0] = (cnt[0] + 1) % 2;
            if (cnt[0] == 0) ++ans;
        } else if (h > 0) {
            if (cnt[h] < 0) ++ans;
            ++cnt[h];
        } else {
            if (cnt[-h] > 0) ++ans;
            --cnt[-h];
        }
    }

    cout << ans << endl;
    return 0;
}
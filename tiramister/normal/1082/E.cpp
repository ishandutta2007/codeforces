#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N, c;
    cin >> N >> c;

    int cnt[N + 1];
    cnt[0] = 0;
    map<int, vector<int>> appear;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        cnt[i] = cnt[i - 1] + (a == c);
        appear[a].push_back(i);
    }

    int ans = cnt[N];
    for (int v = 1; v <= 500000; ++v) {
        if (v == c || appear.find(v) == appear.end()) continue;

        int sum = 0, ma = 0, now = 0;
        for (int i : appear[v]) {
            sum = max(0, sum - (cnt[i] - cnt[now]));
            now = i;
            ++sum;
            ma = max(ma, sum);
        }

        ans = max(ans, cnt[N] + ma);
    }

    cout << ans << endl;
    return 0;
}
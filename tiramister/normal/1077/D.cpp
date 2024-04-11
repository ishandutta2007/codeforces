#include <iostream>
#include <vector>

using namespace std;

const int MAX_S = 200000;

int main() {
    int N, K;
    cin >> N >> K;

    int cnt[MAX_S + 1];
    fill(cnt, cnt + MAX_S + 1, 0);
    for (int i = 0; i < N; ++i) {
        int s;
        cin >> s;
        ++cnt[s];
    }

    int ok = 0, ng = N + 1;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        int c = 0;
        for (int i = 1; i <= MAX_S; ++i) {
            c += cnt[i] / mid;
        }

        if (c >= K) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= MAX_S; ++i) {
        for (int j = 0; j < cnt[i] / ok; ++j) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < K; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
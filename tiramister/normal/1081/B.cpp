#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N];
    queue<int> cnt[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        cnt[a[i]].push(i);
    }

    int ans[N], kind = 1;
    fill(ans, ans + N, -1);

    for (int i = 0; i < N; ++i) {
        if (ans[i] > 0) continue;

        ans[i] = kind;
        cnt[a[i]].pop();
        if (cnt[a[i]].size() < N - a[i] - 1) {
            cout << "Impossible" << endl;
            return 0;
        }

        for (int j = 0; j < N - a[i] - 1; ++j) {
            ans[cnt[a[i]].front()] = kind;
            cnt[a[i]].pop();
        }

        ++kind;
    }

    cout << "Possible" << endl;

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
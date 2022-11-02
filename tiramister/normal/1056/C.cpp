#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int p[N * 2 + 1];
    for (int c = 1; c <= N * 2; ++c) {
        cin >> p[c];
    }

    vector<pair<int, int>> s;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        s.push_back(make_pair(a, b));
    }

    bool used[N * 2 + 1];
    fill(used + 1, used + N * 2 + 1, false);

    int t;
    cin >> t;
    if (t == 2) {
        bool fail = false;
        while (!fail) {
            int c;
            cin >> c;
            used[c] = true;

            fail = true;
            for (auto itr = s.begin(); itr != s.end(); ++itr) {
                auto q = *itr;
                if (q.second == c) swap(q.first, q.second);

                if (q.first == c) {
                    cout << q.second << endl;
                    used[q.second] = true;
                    s.erase(itr);
                    fail = false;
                    break;
                }
            }
        }
    }

    for (auto q : s) {
        if (p[q.first] < p[q.second]) {
            swap(q.first, q.second);
        }
        cout << q.first << endl;
        used[q.first] = true;

        int c;
        cin >> c;
        used[c] = true;
    }

    priority_queue<pair<int, int>> que;
    for (int c = 1; c <= N * 2; ++c) {
        if (used[c]) continue;
        que.push(make_pair(p[c], c));
    }

    while (!que.empty()) {
        int c = que.top().second;
        que.pop();
        if (used[c]) continue;

        cout << c << endl;
        used[c] = true;
        if (que.empty()) break;

        cin >> c;
        used[c] = true;
    }
    return 0;
}
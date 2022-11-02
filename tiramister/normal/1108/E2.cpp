#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 25;

int main() {
    int N, M;
    cin >> N >> M;

    int a[N + 1];
    for (int i = 1; i <= N; ++i) cin >> a[i];

    pair<int, int> segs[M];
    vector<int> lb[N + 1], rb[N + 1];
    // lb[i] = i

    for (int i = 0; i < M; ++i) {
        cin >> segs[i].first >> segs[i].second;

        lb[segs[i].second].push_back(segs[i].first);
        rb[segs[i].first].push_back(segs[i].second);
    }

    int add[N + 1];
    // i

    int lmin[N + 2];
    lmin[0] = INF;
    // lmin[i] = [1, i]
    //           [1, i]

    fill(add, add + N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        lmin[i] = min(lmin[i - 1], a[i]);

        // i
        for (int l : lb[i]) {
            for (int j = l; j <= i; ++j) {
                --add[j];
                lmin[i] = min(lmin[i], a[j] + add[j]);
            }
        }
    }

    int rmin[N + 2];
    rmin[N + 1] = INF;
    // rmin[i] = [i, N]
    //           [i, N]

    fill(add, add + N + 1, 0);
    for (int i = N; i >= 1; --i) {
        rmin[i] = min(rmin[i + 1], a[i]);

        // i
        for (int r : rb[i]) {
            for (int j = r; j >= i; --j) {
                --add[j];
                rmin[i] = min(rmin[i], a[j] + add[j]);
            }
        }
    }

    int ans = 0, center = 0;
    for (int c = 1; c <= N; ++c) {
        // c
        int score = a[c] - min(lmin[c - 1], rmin[c + 1]);
        if (ans < score) {
            ans = score;
            center = c;
        }
    }
    cout << ans << endl;

    // center
    vector<int> ids;
    for (int i = 0; i < M; ++i) {
        if (segs[i].first <= center && center <= segs[i].second) continue;
        ids.push_back(i + 1);
    }

    cout << ids.size() << endl;
    for (int id : ids) {
        cout << id << " ";
    }
    cout << endl;
    return 0;
}
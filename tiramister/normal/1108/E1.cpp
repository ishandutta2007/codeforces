#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1 << 25;

int main() {
    int N, M;
    cin >> N >> M;

    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    int l[M], r[M];
    for (int j = 0; j < M; ++j) {
        cin >> l[j] >> r[j];
        --l[j], --r[j];
    }

    int center = 0, maxscore = -INF;
    for (int c = 0; c < N; ++c) {
        int b[N];
        copy(a, a + N, b);

        for (int j = 0; j < M; ++j) {
            if (l[j] <= c && c <= r[j]) continue;
            for (int i = l[j]; i <= r[j]; ++i) --b[i];
        }

        int score = b[c] - *min_element(b, b + N);
        if (score > maxscore) {
            maxscore = score;
            center = c;
        }
    }

    cout << maxscore << endl;

    vector<int> segs;
    for (int j = 0; j < M; ++j) {
        if (l[j] <= center && center <= r[j]) continue;
        segs.push_back(j);
    }

    cout << segs.size() << endl;
    for (int j : segs) cout << j + 1 << " ";
    cout << endl;
    return 0;
}
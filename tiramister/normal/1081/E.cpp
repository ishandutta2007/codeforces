#include <iostream>

using namespace std;
using ll = long long;

const int INF = 1 << 25;

pair<int, int> divide(int x, int d) {
    if (x % d > 0) return make_pair(-INF, -INF);
    return make_pair(x / d - (d - 1), x / d + (d - 1));
}

int main() {
    int N;
    cin >> N;
    N /= 2;

    int x[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    pair<int, int> range[N + 1];
    range[N] = make_pair(INF, INF);

    for (int i = N - 1; i >= 0; --i) {
        bool decided = false;
        for (int d = 1; d < 1000; ++d) {
            auto p = divide(x[i], d);
            if (p.first < 3 || p.first % 2 == 0 || p.second >= range[i + 1].first) continue;
            decided = true;
            range[i] = p;
            break;
        }

        if (!decided) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    int cur = 1;
    for (int i = 0; i < N; ++i) {
        ll sum = 0;
        while (cur < range[i].first) {
            sum += cur;
            cur += 2;
        }
        cout << sum << " ";

        sum = 0;
        while (cur <= range[i].second) {
            sum += cur;
            cur += 2;
        }
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}
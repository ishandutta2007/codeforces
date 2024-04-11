#include <iostream>

using namespace std;

const int INF = 1 << 30;

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int ans = INF, to = 1;
    for (int t = 1; t <= 100; ++t) {
        int cost = 0;
        for (int i = 0; i < N; ++i) {
            if (a[i] < t) {
                cost += (t - 1) - a[i];
            } else if (a[i] > t) {
                cost += a[i] - (t + 1);
            }
        }

        if (ans > cost) {
            ans = cost;
            to = t;
        }
    }

    cout << to << " " << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 25;

int main() {
    int N, R;
    cin >> N >> R;
    vector<int> heater;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        if (a == 1) heater.push_back(i);
    }

    int ans = 0, pos = 1;
    while (pos <= N) {
        int on = -INF;
        for (int h : heater) {
            if (h - R + 1 <= pos && pos <= h + R - 1) on = h;
        }

        if (on + R <= pos) {
            cout << -1 << endl;
            return 0;
        } else {
            ++ans;
            pos = on + R;
        }
    }

    cout << ans << endl;
    return 0;
}
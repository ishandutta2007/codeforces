#include <bits/stdc++.h>
using namespace std;

const int N = 30000 + 1;

int max_speed[N], min_speed[N], gems[N];
vector<int> max_gems[N];

void set_max(int &a, int b) {
    if (b > a) {
        a = b;
    }
}

void set_min(int &a, int b) {
    if (b < a) {
        a = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    fill(min_speed, min_speed + N, INT_MAX);
    min_speed[d] = max_speed[d] = d;

    for (int i = d; i < N; ++i) {
        for (int j = min_speed[i]; j <= max_speed[i]; ++j) {
            for (int k = j - 1; k <= j + 1; ++k) {
                if (k > 0 && i + k < N) {
                    set_max(max_speed[i + k], k);
                    set_min(min_speed[i + k], k);
                }
            }
        }
        if (max_speed[i] >= min_speed[i]) {
            max_gems[i].resize(max_speed[i] - min_speed[i] + 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        ++gems[p];
    }

    int ans = 0;
    max_gems[d][0] = gems[d];
    for (int i = d; i < N; ++i) {
        for (int j = min_speed[i]; j <= max_speed[i]; ++j) {
            ans = max(ans, max_gems[i][j - min_speed[i]]);
            for (int k = j - 1; k <= j + 1; ++k) {
                if (k > 0 && i + k < N) {
                    set_max(max_gems[i + k][k - min_speed[i + k]],
                        max_gems[i][j - min_speed[i]] + gems[i + k]);
                }
            }
        }
    }

    cout << ans << "\n";
}
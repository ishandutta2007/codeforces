#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int width[N], height[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> width[i] >> height[i];
    }

    int ans = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        int space = n / 2, sum = 0;
        vector<int> flip;

        for (int j = 0; j < n; ++j) {
            if (height[j] > i) {
                if (width[j] > i) {
                    space = -1;
                } else {
                    sum += height[j];
                    --space;
                }
            } else {
                if (width[j] > height[j] && width[j] <= i) {
                    flip.push_back(width[j] - height[j]);
                }
                sum += width[j];
            }
        }

        sort(flip.begin(), flip.end());
        while (space > 0 && !flip.empty()) {
            sum -= flip.back();
            flip.pop_back();
            --space;
        }

        if (space >= 0) {
            ans = min(ans, i * sum);
        }
    }

    cout << ans << "\n";
}
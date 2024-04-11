#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

int mini[N], maxi[N], ans[N], a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    mini[0] = -N, maxi[0] = N;
    for (int i = 1; i < n; ++i) {
        mini[i] = min(a[i] < a[i - 1] ? mini[i - 1] : N, a[i] < maxi[i - 1] ? a[i - 1] : N);
        maxi[i] = max(a[i] > a[i - 1] ? maxi[i - 1] : -N, a[i] > mini[i - 1] ? a[i - 1] : -N);
    }

    if (mini[n - 1] == N && maxi[n - 1] == -N) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        ans[n - 1] = mini[n - 1] < N;
        for (int i = n - 1; i > 0; --i) {
            if (ans[i] == 0) {
                ans[i - 1] = a[i] > mini[i - 1] && a[i - 1] == maxi[i];
            } else {
                ans[i - 1] = a[i] < a[i - 1] && mini[i - 1] == mini[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
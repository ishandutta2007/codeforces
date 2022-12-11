#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int test;
int n, a[N][3];
int best[N];

int last[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][2];
        a[i][0] = 1, a[i][1] = i;
    }
    cin >> test;
    for(int i = 1; i <= test; i++) {
        cin >> a[n + i][0];
        for(int j = 1; j <= 3 - a[n + i][0]; j++) {
            cin >> a[n + i][j];
        }
    }

    for(int i = 1; i <= n + test; i++) if (a[i][0] == 1) {
        last[a[i][1]] = i;
    }

    for(int i = n + test; i >= 1; i--) {
        best[i] = best[i + 1];
        if (a[i][0] == 2) {
            best[i] = max(best[i], a[i][1]);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << max(a[last[i]][2], best[last[i]]) << " ";
    }
}
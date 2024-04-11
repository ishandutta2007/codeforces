#include <iostream>

using namespace std;

const int MAX_N = 100000, INF = 1e9 + 7;
int a[MAX_N], b[MAX_N];

int check(int n) {
    int d = b[1] - b[0], ans = 0;
    for (int i = 2; i < n; i++) {
        if (b[i] - b[i - 1] == d) continue;
        ans++;
        if (b[i] - b[i - 1] == d + 1) b[i]--;
        else if (b[i] - b[i - 1] == d - 1) b[i]++;
        else return INF;
    }
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    int ans = INF, add;
    for (int c1 = -1; c1 <= 1; c1++) {
        for (int c2 = -1; c2 <= 1; c2++) {
            for (int i = 0; i < n; i++) {
                b[i] = a[i];
            }
            add = 0;
            if (c1 != 0) add = 1;
            if (c2 != 0) add += 1;
            b[0] += c1;
            b[1] += c2;
            ans = min(ans, check(n) + add);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
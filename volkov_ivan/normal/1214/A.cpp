#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;

int main() {
    int n, d, e;
    cin >> n >> d >> e;
    int mini = n;
    for (int i = 0; i < N; i++) {
        if (d * i > n) break;
        int rest = n - d * i;
        mini = min(mini, rest % (e * 5));
    }
    cout << mini << endl;
    return 0;
}
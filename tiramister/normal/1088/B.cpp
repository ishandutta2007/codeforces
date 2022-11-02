#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N + 1);
    a[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    // a

    for (int k = 0; k < K; ++k) {
        if (k < a.size() - 1) {
            cout << a[k + 1] - a[k] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
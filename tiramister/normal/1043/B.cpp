#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N + 1];
    a[0] = 0;
    for (int i = 1; i <= N; ++i) cin >> a[i];

    int d[N];
    for (int i = 0; i < N; ++i) d[i] = a[i + 1] - a[i];

    vector<int> ans;
    for (int k = 1; k <= N; ++k) {
        bool judge = true;
        for (int i = 0; i < N; ++i) {
            if (d[i % k] != d[i]) judge = false;
        }
        if (judge) ans.push_back(k);
    }

    cout << ans.size() << endl;
    for (int e : ans) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
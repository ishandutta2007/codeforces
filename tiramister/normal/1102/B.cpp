#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int a[N];
    vector<int> index[5001];

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        index[a[i]].push_back(i);
    }

    int ans[N], color = 0;
    for (int k = 1; k <= 5000; ++k) {
        if (index[k].size() > K) {
            cout << "NO" << endl;
            return 0;
        }

        for (int i : index[k]) {
            ans[i] = color % K + 1;
            ++color;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
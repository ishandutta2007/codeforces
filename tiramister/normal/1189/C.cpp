#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> sum(N + 1);
    sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        int A;
        cin >> A;
        sum[i] += sum[i - 1] + A;
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        cout << (sum[r] - sum[l - 1]) / 10 << endl;
    }
    return 0;
}
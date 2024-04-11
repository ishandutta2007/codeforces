#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    sort(A.rbegin(), A.rend());

    if (A[0] >= A[1] + A[2]) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) cout << A[i] << " ";
    }
    for (int i = N - 1; i >= 0; --i) {
        if (i % 2 == 1) cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
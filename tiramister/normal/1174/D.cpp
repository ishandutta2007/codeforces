#include <iostream>
#include <numeric>
#include <vector>

// 0-indexed
template <class T, class U>
inline T kthbit(T a, U k) { return (a >> k) & 1; }


using namespace std;

vector<int> idx;
// 2^i

// 1, 2, 1, 4, 1, 2, 1, ...
void rec(int N) {
    if (N < 0) return;
    rec(N - 1);
    cout << (1 << idx[N]) << " ";
    rec(N - 1);
}

int main() {
    int N, X;
    cin >> N >> X;

    if (X >= (1 << N)) {
        cout << (1 << N) - 1 << endl;

        // idx0, 1, ...
        idx.resize(N);
        iota(idx.begin(), idx.end(), 0);
        rec(N - 1);
    } else {
        cout << (1 << (N - 1)) - 1 << endl;

        // iidx
        idx.resize(N - 1);
        bool skipped = false;
        for (int i = 0; i < N; ++i) {
            if (kthbit(X, i) && !skipped) {
                skipped = true;
            } else {
                idx[i - skipped] = i;
            }
        }
        rec(N - 2);
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

using ll = long long;

int main() {
    int N;
    ll K;
    cin >> N >> K;

    string S, T;
    cin >> S >> T;

    if (K == 1) {
        cout << N << endl;
        return 0;
    }

    ll w[N], d[N];
    int itr;
    for (itr = 0; itr < N; ++itr) {
        if (S[itr] != T[itr]) break;
        w[itr] = 1;
    }

    if (itr == N) {
        cout << N << endl;
        return 0;
    }

    w[itr] = 2, d[itr] = 0;
    ++itr;
    for (; itr < N; ++itr) {
        // free node + 
        w[itr] = w[itr - 1] + d[itr - 1];
        d[itr] = d[itr - 1] * 2;
        if (S[itr] == 'a') {
            ++w[itr];
            ++d[itr];
        }
        if (T[itr] == 'b') {
            ++w[itr];
            ++d[itr];
        }

        if (w[itr] >= K) break;
    }

    for (; itr < N; ++itr) w[itr] = K;

    cout << accumulate(w, w + N, 0LL) << endl;
    return 0;
}
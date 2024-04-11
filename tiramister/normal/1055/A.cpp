#include <iostream>

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    --S;

    int a[N], b[N];
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    if (a[0] && a[S]) {
        cout << "YES" << endl;
        return 0;
    }

    for (int k = S + 1; k < N; ++k) {
        if (a[0] && a[k] && b[k] && b[S]) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
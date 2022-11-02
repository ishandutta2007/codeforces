#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }

    if (all_of(a, a + N, [&](int i) { return i == 0; })) {
        cout << "YES" << endl;
        return 0;
    }

    for (int s = 1; s < accumulate(a, a + N, 0); ++s) {
        int sum = 0;
        bool judge = true;
        for (int i = 0; i < N; ++i) {
            if (sum + a[i] < s) {
                sum += a[i];
            } else if (sum + a[i] == s) {
                sum = 0;
            } else {
                judge = false;
                break;
            }
        }

        if (judge && sum == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
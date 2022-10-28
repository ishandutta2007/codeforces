#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 1;

long long ways[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ways[0] = ways[1] = 1;
    for (int i = 2; i < N; ++i) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    int n;
    long long k;
    cin >> n >> k;

    int i = 1;
    while (i <= n ) {
        if (ways[n - i] < k) {
            k -= ways[n - i];
            cout << i + 1 << " " << i << " ";
            i += 2;
        } else {
            cout << i << " ";
            ++i;
        }
    }

    cout << "\n";
}
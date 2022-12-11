#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<int> a[2];
        for(int row = 0; row <= 1; row++) {
            a[row].resize(n);
            for(int col = 0; col < n; col++) cin >> a[row][col];
        }
        int answer = 0;

        array<int, 2> countB = {0, 0};
        for(int col = 0; col < n; col++) {
            for(int row = 0; row <= 1; row++) countB[row] += a[row][col];
            answer += a[0][col] != a[1][col];
        }
        cout << min(answer, abs(countB[0] - countB[1]) + 1) << '\n';
    }

}
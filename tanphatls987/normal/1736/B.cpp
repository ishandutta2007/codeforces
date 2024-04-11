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
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];


        vector<int> b(n + 1);
        b[0] = a[0], b[n] = a[n - 1];
        for(int i = 1; i < n; i++) b[i] = a[i - 1] * a[i] / __gcd(a[i - 1], a[i]);

        string answer = "YES";
        for(int i = 0; i < n; i++) if (__gcd(b[i], b[i + 1]) != a[i]) {
            answer = "NO";
        }
        cout << answer << '\n';
    }

}
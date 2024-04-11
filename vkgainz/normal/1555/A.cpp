#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        long long n; cin >> n;
        long long time = 1e18;
        for(int a = 0; a <= 10; a++) {
            long long left = n - 10 * a;
            left = max(left, 0LL);
            time = min(time, 25 * a + (left + 5) / 6 * 15);
            left = n - 8 * a;
            left = max(left, 0LL);
            time = min(time, 20 * a + (left + 5) / 6 * 15);
        }
        cout << time << "\n";
    }
}
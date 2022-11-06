#include <iostream>

using namespace std;

int n, m, k, counter;
long long arr[1000];

bool check(long long a, long long b) {
    long long ans = 0, c = a ^ b;
    while (c > 0) {
        ans += c % 2;
        c /= 2;
    }
    return ans <= k;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }
    cin >> n;
    for (int i = 0; i < m; ++i) {
        if (check(n, arr[i])) {
            counter++;
        }
    }
    cout << counter;
}
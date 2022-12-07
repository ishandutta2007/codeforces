#include <vector>
#include <iostream>
using namespace std;

int n;
int a[100000];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int solve() {
    cin >> n;
    int ma = 0;
    int g = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ma = max(ma, a[i]);
        g = gcd(a[i], g);
    }
    return ma / g;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << endl;
    }
}
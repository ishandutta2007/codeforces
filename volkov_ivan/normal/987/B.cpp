#include <iostream>

using namespace std;

long long pow(long long a, long long b) {
    long long ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}

int main() {
    long long x, y;
    cin >> x >> y;
    if (x == y) {
        cout << "=" << endl;
        return 0;
    }
    if (x == 1) {
        cout << "<" << endl;
        return 0;
    }
    if (y == 1) {
        cout << ">" << endl;
        return 0;
    }
    if (x <= 10 && y <= 10) {
        long long a = pow(x, y);
        long long b = pow(y, x);
        if (a == b) cout << "=" << endl;
        else if (a < b) cout << "<" << endl;
        else cout << ">" << endl;
        return 0;
    }
    if (x < y) cout << ">" << endl;
    else cout << "<" << endl;
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0, c;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            c = a ^ b;
            if (c >= b && c <= n && a + b > c) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
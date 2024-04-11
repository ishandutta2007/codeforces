#include <cstdio>
#include <iostream>
using namespace std;
int n, a, b, c;
void que(int pos) {
    if (pos > 1) {
        cout << "? " << pos - 1 << endl;
        cin >> a;
    } else
        a = 1e9;
    cout << "? " << pos << endl;
    cin >> b;
    if (pos < n) {
        cout << "? " << pos + 1 << endl;
        cin >> c;
    } else
        c = 1e9;
}
int main() {
    scanf("%d", &n);
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        que(mid);
        if (b < a && b < c) {
            cout << "! " << mid << endl;
            return 0;
        }
        if (a < b && b < c)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}
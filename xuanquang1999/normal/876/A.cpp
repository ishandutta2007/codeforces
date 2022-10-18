#include <iostream>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n == 1)
        cout << 0;
    else {
        int x = min(a, b);
        if (c > x)
            cout << x*(n-1);
        else
            cout << x+c*(n-2);
    }
}
#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    while (x%10 == 0) x /= 10;

    int a = x, revX = 0;
    while (a > 0) {
        revX = 10*revX + a%10;
        a /= 10;
    }

    if (x == revX) cout << "YES";
    else cout << "NO";
}
//
// Created by Danny Mittal on 6/25/19.
//

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    int a = 0;
    int b = (n * m) - 1;
    while (a <= b) {
        cout << (a / m) + 1 << " " << (a % m) + 1 << "\n";
        a++;
        if (b < a) {
            break;
        }
        cout << (b / m) + 1 << " " << (b % m) + 1 << "\n";
        b--;
    }
    cout << flush;
}
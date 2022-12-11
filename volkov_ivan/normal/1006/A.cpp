#include <iostream>

using namespace std;

int main() {
    int n;
    cin  >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) a--;
        cout << a << ' ';
    }
    return 0;
}
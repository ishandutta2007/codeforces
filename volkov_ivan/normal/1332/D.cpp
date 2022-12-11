#include <iostream>

using namespace std;

const int C = 18;

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int k;
    cin >> k;
    cout << 2 << ' ' << 3 << endl;
    int maxi = (1 << C) - 1;
    int rest = maxi - k;
    cout << maxi << ' ' << k << ' ' << 0 << endl;
    cout << rest << ' ' << maxi << ' ' << k << endl;
    return 0;
}
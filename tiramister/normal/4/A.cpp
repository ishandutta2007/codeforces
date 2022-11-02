#include <iostream>

using namespace std;

int main() {
    int W;
    cin >> W;
    cout << (W > 2 && W % 2 == 0 ? "YES" : "NO") << endl;
    return 0;
}
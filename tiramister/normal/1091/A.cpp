#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int y, b, r;
    cin >> y >> b >> r;

    r -= 2, b -= 1;
    int n = min({y, b, r});
    cout << n * 3 + 3 << endl;
    return 0;
}
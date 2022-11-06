#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

int a, b, c;
main() {
    cin >> a >> b >> c;
    cout << max(max(max((a + b + c), (a * b * c)), max((a + b * c), ((a + b) * c))), max((a * b + c), (a * (b + c))));
}
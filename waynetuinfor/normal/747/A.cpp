#include <iostream>
#include <cmath>
using namespace std;

int n, sq;

int main() {
    cin >> n;
    sq = (int)sqrt(n);
    while (n % sq) sq--;
    cout << sq << ' ' << n / sq << '\n';
    return 0;
}
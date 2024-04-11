#include <bits/stdc++.h>


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);

    int64_t X, Y, Z;
    cin >> X >> Y >> Z;

    int length = 0;
    cout << (X != Y ? min(X, Y) * 2 + 1 + Z * 2 : 2 * X + 2 * Z) << '\n';
}
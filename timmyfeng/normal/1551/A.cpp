#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;

        cout << (a / 3 + (a % 3 == 1)) << " " << (a / 3 + (a % 3 == 2)) << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l = 0, r = 0, n;
    cin >> n;
    cin.ignore();
    while (n--)
        if (cin.get() == 'L') l++;
        else r++;
    cout << l + r + 1 << "\n";
}
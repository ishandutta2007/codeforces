#include <bits/stdc++.h>
using namespace std;

int main() {
    int a; cin >> a;
    string b; cin >> b;
    reverse(b.begin(), b.end());
    stringstream ss(b);
    int bb; ss >> bb;
    return cout << a + bb << '\n', 0;
}
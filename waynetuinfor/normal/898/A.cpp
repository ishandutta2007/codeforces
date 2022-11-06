#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int to = n - n % 10, toto = n - n % 10 + 10;
    cout << (abs(n - to) < abs(n - toto) ? to : toto) << endl;
    return 0;
}
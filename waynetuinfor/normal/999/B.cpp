#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) if (n % i == 0) reverse(s.begin(), s.begin() + i);
    cout << s << endl;
    return 0;
}
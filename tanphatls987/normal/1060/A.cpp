#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int d8 = count(s.begin(), s.end(), '8');
    cout << min(n / 11, d8);
}
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cout << (s.front() == s.back() ? "-1" : s) << endl;
    }
    return 0;
}
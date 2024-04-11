#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            cout << "YES" << endl;
            cout << s.substr(i, 2) << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
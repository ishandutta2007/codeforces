#include <iostream>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            if (i > 0 && s[i - 1] == '1') {
                cout << "NO" << endl;
                return 0;
            }
        }
        if (s[i] == '0') {
            if ((i == 0 || s[i - 1] == '0') && (i == n - 1 || s[i + 1] == '0')) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
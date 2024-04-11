#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'o') a++;
        else b++;
    }
    if (a == 0 || b % a == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
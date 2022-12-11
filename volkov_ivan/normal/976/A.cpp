#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    if (s == "0") {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++) if (s[i] == '0') cnt++;
    cout << 1;
    for (int i = 0; i < cnt; i++) cout << 0;
    cout << endl;
    return 0;
}
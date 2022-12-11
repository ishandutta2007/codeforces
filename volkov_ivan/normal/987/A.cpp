#include <iostream>

using namespace std;

int main() {
    bool used[6] = {0, 0, 0, 0, 0, 0};
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "purple") used[0] = 1;
        if (s == "green") used[1] = 1;
        if (s == "blue") used[2] = 1;
        if (s == "orange") used[3] = 1;
        if (s == "red") used[4] = 1;
        if (s == "yellow") used[5] = 1;
    }
    cout << 6 - n << endl;
    if (!used[0]) cout << "Power" << endl;
    if (!used[1]) cout << "Time" << endl;
    if (!used[2]) cout << "Space" << endl;
    if (!used[3]) cout << "Soul" << endl;
    if (!used[4]) cout << "Reality" << endl;
    if (!used[5]) cout << "Mind" << endl;
    return 0;
}
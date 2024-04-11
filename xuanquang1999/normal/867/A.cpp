#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int cntSF = 0, cntFS = 0;
    for(int i = 1; i < n; ++i) {
        if (s[i-1] == 'S' && s[i] == 'F') ++cntSF;
        if (s[i-1] == 'F' && s[i] == 'S') ++cntFS;
    }

    if (cntSF > cntFS) cout << "YES";
    else cout << "NO";
}
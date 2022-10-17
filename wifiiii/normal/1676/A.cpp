#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int x = 0, y = 0;
        for(int i = 0; i < 3; ++i) {
            x += s[i] - '0';
        }
        for(int i = 3; i < 6; ++i) {
            y += s[i] - '0';
        }
        cout << (x == y ? "Yes" : "No") << '\n';
    }
}
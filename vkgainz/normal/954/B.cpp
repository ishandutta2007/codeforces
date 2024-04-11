#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int mv = 0;
    for (int i = 0; 2 * i + 1 < n; i++) {
        string a = s.substr(0, i + 1);
        string b = s.substr(i + 1, i + 1);
        if (a == b) {
            mv = i + 1;
        }
    }
    cout << min(n, n - mv + 1) << "\n";
}
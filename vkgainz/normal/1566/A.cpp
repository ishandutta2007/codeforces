#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        cout << s / (n / 2 + 1) << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h, x, y; cin >> w >> h >> x >> y;
    if (x < w) {
        cout << h + y + 2 + h + y + 2 + w + w << endl;
    } else {
        cout << h + y + 2 + h + y + 2 + w + w << endl;
    }
}
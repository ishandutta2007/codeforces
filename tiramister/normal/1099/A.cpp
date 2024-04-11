#include <iostream>

using namespace std;

int main() {
    int w, h;
    cin >> w >> h;

    int s[h + 1];
    fill(s, s + h + 1, 0);

    for (int i = 0; i < 2; ++i) {
        int u, d;
        cin >> u >> d;
        s[d] += u;
    }

    while (h >= 0) {
        w += h;
        w = max(0, w - s[h]);
        --h;
    }

    cout << w << endl;
    return 0;
}
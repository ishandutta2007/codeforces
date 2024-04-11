#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    pair<int, int> coo[3];

    int miy = 1000, may = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> coo[i].first >> coo[i].second;
        miy = min(miy, coo[i].second);
        may = max(may, coo[i].second);
    }

    sort(coo, coo + 3);

    cout << (may - miy) + (coo[2].first - coo[0].first) + 1 << "\n";

    for (int y = miy; y <= may; ++y) {
        cout << coo[1].first << " " << y << "\n";
    }

    for (int x = coo[0].first; x < coo[1].first; ++x) {
        cout << x << " " << coo[0].second << "\n";
    }

    for (int x = coo[1].first + 1; x <= coo[2].first; ++x) {
        cout << x << " " << coo[2].second << "\n";
    }
    return 0;
}
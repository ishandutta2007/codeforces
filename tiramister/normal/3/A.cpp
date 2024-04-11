#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> calc(int sx, int sy, int gx, int gy) {
    string mov;
    if (sx < gx) {
        mov.push_back('R');
        ++sx;
    } else if (sx > gx) {
        mov.push_back('L');
        --sx;
    }

    if (sy < gy) {
        mov.push_back('U');
        ++sy;
    } else if (sy > gy) {
        mov.push_back('D');
        --sy;
    }

    if (mov.empty()) {
        return vector<string>();
    } else {
        auto res = calc(sx, sy, gx, gy);
        res.push_back(mov);
        return res;
    }
}

int main() {
    int x[2], y[2];
    for (int i = 0; i < 2; ++i) {
        char c;
        cin >> c;
        x[i] = c - 'a';
        cin >> y[i];
    }

    vector<string> ans = calc(x[0], y[0], x[1], y[1]);

    cout << ans.size() << endl;
    while (!ans.empty()) {
        cout << ans.back() << endl;
        ans.pop_back();
    }
    return 0;
}
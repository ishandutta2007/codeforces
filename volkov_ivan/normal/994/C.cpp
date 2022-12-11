#include <iostream>
#include <set>

using namespace std;

int main() {
    set <pair <int, int>> ok;
    int min_x, max_x, min_y, max_y, c_x, c_y, min_x2, min_y2, max_x2, max_y2, c_x2, c_y2, x, y, len1, len2;
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        if (i == 0) {
            min_x = max_x = x;
            min_y = max_y = y;
        } else {
            min_x = min(x, min_x);
            min_y = min(y, min_y);
            max_x = max(x, max_x);
            max_y = max(y, max_y);
        }
    }
    //c_x = (min_x + max_x) / 2;
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        if (i == 0) {
            min_x2 = max_x2 = x;
            min_y2 = max_y2 = y;
        } else {
            min_x2 = min(x, min_x2);
            min_y2 = min(y, min_y2);
            max_x2 = max(x, max_x2);
            max_y2 = max(y, max_y2);
        }
    }
    c_x2 = (min_x2 + max_x2) / 2;
    c_y2 = (min_y2 + max_y2) / 2;
    len2 = max_y2 - c_y2;
    int d = len2 + 1;
    for (int x = c_x2; x >= min_x2; x--) {
        for (int pl = 0; pl <= d; pl++) {
            ok.insert({x, c_y2 + pl});
            if (pl != d) ok.insert({x, c_y2 - pl});
        }
        //ok.insert({x, max_y2 + 1});
        //cout << d << endl;
        d--;
    }
    d = len2 + 1;
    for (int x = c_x2; x <= max_x2; x++) {
        for (int pl = 0; pl <= d; pl++) {
            ok.insert({x + 1, c_y2 + pl});
            if (pl != d) ok.insert({x+ 1, c_y2 - pl});
        }
        //cout << d << endl;
        d--;
    }
    /*for (auto elem : ok) {
        cout << elem.first << ' ' << elem.second << endl;
    }*/
    for (int x = min_x + 1; x <= max_x; x++) {
        for (int y = min_y + 1; y <= max_y; y++) {
            if (ok.find({x, y}) != ok.end()) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
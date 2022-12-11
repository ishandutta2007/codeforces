#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        int cnt_all = b / 2;
        int res = 0;
        if (h > c) {
            res += min(cnt_all, p) * h;
            cnt_all -= min(cnt_all, p);
            res += min(cnt_all, f) * c;
        } else {
            res += min(cnt_all, f) * c;
            cnt_all -= min(cnt_all, f); 
            res += min(cnt_all, p) * h;
        }
        cout << res << endl;
    }
    return 0;
}
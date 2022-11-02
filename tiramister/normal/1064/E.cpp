#include <iostream>

using namespace std;

bool query(int x, int y) {
    cout << x << " " << y << endl;
    string res;
    cin >> res;
    return res == "white";
}

int main() {
    int N;
    cin >> N;

    int l = 0, r = (1 << 29);
    bool lower = query(1, 0);
    for (int i = 0; i < N - 1; ++i) {
        int mid = (l + r) / 2;
        if (query(1, mid) == lower) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << 0 << " " << l << " " << 2 << " " << r << endl;
    return 0;
}
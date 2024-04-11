#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    int pos[200010];
    int l = 1, r = 0;
    for (int q = 0; q < Q; ++q) {
        char t;
        int id;
        cin >> t >> id;
        --id;

        if (t == 'L') {
            pos[id] = --l;
        } else if (t == 'R') {
            pos[id] = ++r;
        } else {
            cout << min(abs(pos[id] - l), abs(r - pos[id])) << endl;
        }
    }
    return 0;
}
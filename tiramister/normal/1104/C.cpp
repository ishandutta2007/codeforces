#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int zid = 0, oid = 0;
    for (char c : S) {
        if (c == '0') {
            cout << 1 << " " << zid + 1 << endl;
            zid = (zid + 1) % 4;
        } else {
            cout << 3 << " " << oid * 2 + 1 << endl;
            oid = (oid + 1) % 2;
        }
    }
    return 0;
}
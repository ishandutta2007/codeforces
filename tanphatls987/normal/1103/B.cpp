#include <bits/stdc++.h>

using namespace std;

char ask(int L, int R) {
    cout << "? " << L << " " << R << endl;
    char ans; cin >> ans;
    return ans;
}
int main() {
    string flag; 
    while (1) {
        cin >> flag; if (flag == "end") break;
        for(int lv = 0; ; lv++) {
            if (lv == 30) {
                cout << "! 1\n";
                break;
            }
            if (ask(1 << (lv + 1), 1 << lv) == 'y') {
                ///L < x < 2 * L < 2 * x -> 2 * L - x < L

                int L = 1, R = 1 << lv;
                int st = 1 << lv;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (ask(st, st + mid) == 'y') L = mid + 1;
                    else R = mid - 1;
                }
                cout << "! " << st + L << '\n';
                break;
            }
        }
    }
}
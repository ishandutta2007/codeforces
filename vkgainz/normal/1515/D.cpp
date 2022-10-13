#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, l, r; cin >> n >> l >> r;
        vector<int> c(n);
        vector<int> num(n);
        for(int i = 0; i < n; i++) {
            cin >> c[i], --c[i];
            if(i < l) ++num[c[i]];
            else --num[c[i]];
        }
        int le = 0, ri = 0;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(num[i] < 0) {
                num[i] = abs(num[i]);
                a += num[i];
                if(num[i] % 2)
                    le++;
            }
            else {
                b += num[i];
                if(num[i] % 2)
                    ri++;
            }
        }
        int put = a + b;
        if(a < b) {
            cout << (put + max(ri - a, 0)) / 2 << "\n";
        }
        else {
            cout << ((put + max(le - b, 0)) / 2) << "\n";
        }

    }
}
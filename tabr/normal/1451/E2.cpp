#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n, -1);
    set<int> st;
    st.emplace(0);
    int b = -1;
    for (int i = 1; i < n; i++) {
        cout << "XOR 1 " << i + 1 << endl;
        cin >> a[i];
        if (st.count(a[i])) {
            b = a[i];
        }
        st.emplace(a[i]);
    }
    if (b == 0) {
        for (int i = 1; i < n; i++) {
            if (a[i] == 0) {
                cout << "AND 1 " << i + 1 << endl;
                cin >> a[0];
                break;
            }
        }
    } else if (b != -1) {
        for (int i = 1; i < n; i++) {
            if (a[i] == b) {
                for (int j = i + 1; j < n; j++) {
                    if (a[j] == b) {
                        cout << "AND " << i + 1 << " " << j + 1 << endl;
                        cin >> b;
                        a[0] = b ^ a[j];
                        break;
                    }
                }
                break;
            }
        }
    } else {
        int x, y;
        for (int i = 1; i < n; i++) {
            if (a[i] == 1) {
                cout << "AND 1 " << i + 1 << endl;
                cin >> x;
            } else if (a[i] == 2) {
                cout << "AND 1 " << i + 1 << endl;
                cin >> y;
            }
        }
        a[0] = x;
        a[0] |= y & 1;
    }
    for (int i = 1; i < n; i++) {
        a[i] ^= a[0];
    }
    cout << "! ";
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
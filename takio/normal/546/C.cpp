#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

deque <int> a, b;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, n1, n2, x;
    cin >> n >> n1;
    for (int i = 1; i <= n1; i++) {
        cin >> x;
        a.push_back(x);
    }
    cin >> n2;
    for (int i = 1; i <= n2; i++) {
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i <= 20000000; i++) {
        if (a.size() == 0) {
            cout << i << ' ' << 2 << endl;
            return 0;
        }
        if (b.size() == 0) {
            cout << i << ' ' << 1 << endl;
            return 0;
        }
        int ta = a.front(); a.pop_front();
        int tb = b.front(); b.pop_front();
//        cout << ta << ' ' << tb << endl;
        if (ta > tb) {
            a.push_back(tb);
            a.push_back(ta);
        } else {
            b.push_back(ta);
            b.push_back(tb);
        }
    }
    cout << -1 <<endl;
}
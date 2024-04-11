#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;

map <LL, LL> mp;

int main () {
//    freopen ("in.txt", "r", stdin);
    LL q, t, x, y, c;
    cin >> q;
    while (q--) {
        cin >> t >> x >> y;
        set <LL> st;
        if (t == 1) {
            scanf ("%d", &c);
            while (x) {
                mp[x] += c;
                st.insert (x);
                x /= 2;
            }
            int flag = 1;
            while (y) {
                if (st.find (y) != st.end ()) flag = -1;
                mp[y] += c * flag;
                y /= 2;
            }
        } else {
            LL res = 0;
            while (x) {
                res += mp[x];
                st.insert (x);
                x /= 2;
            }
            int flag = 1;
            while (y) {
                if (st.find (y) != st.end ()) flag = -1;
                res += mp[y] * flag;
                y /= 2;
            }
            cout << res << endl;
        }
    }
}
#include <iostream>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s, t;
        cin >> s >> t;
        set <char> st;
        for (int i = 0; i < (int) s.length(); i++) {
            st.insert(s[i]);
        }
        bool flag = 0;
        for (int j = 0; j < (int) t.length(); j++) {
            if (st.find(t[j]) != st.end()) {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "NO" << endl;
    }
    return 0;
}
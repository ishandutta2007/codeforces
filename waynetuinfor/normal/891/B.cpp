#include <bits/stdc++.h>
using namespace std;

const int maxn = 22;
int a[maxn];

int main() {
    int n; cin >> n;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        auto it = st.upper_bound(a[i]);
        if (it == st.end()) it = st.begin();
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct knight {
    long long p, c, i;
    bool operator<(knight k) const {
        return p < k.p;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    knight knights[n];
    long long ans[n];
    multiset<int> st;
    for (int i = 0; i < n; i++) cin >> knights[i].p;
    for (int i = 0; i < n; i++) cin >> knights[i].c;
    for (int i = 0; i < n; i++) knights[i].i = i;
    sort(knights, knights + n);
    for (int i = 0; i < n; i++) {
        ans[knights[i].i] = knights[i].c;
        int kct = k;
        for (multiset<int>::reverse_iterator it = st.rbegin(); it != st.rend() && kct; it++) {
            ans[knights[i].i] += *it;
            kct--;
        }
        st.insert(knights[i].c);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
    return 0;
}
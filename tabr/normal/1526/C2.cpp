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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    int pos = 0;
    long long neg = 0;
    multiset<long long> st;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            pos++;
            sum += a[i];
            continue;
        }
        a[i] = abs(a[i]);
        st.emplace(a[i]);
        neg += a[i];
        while (sum < neg) {
            long long t = *st.rbegin();
            neg -= t;
            st.erase(st.find(t));
        }
    }
    cout << pos + (int) st.size() << '\n';
    return 0;
}
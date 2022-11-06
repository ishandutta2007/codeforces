#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int a[maxn], s[maxn], type;

struct line {
    int a, b, l, r;
    int intersect(const line& rhs) const {
        return (rhs.b - b) / (a - rhs.a);
    }
    int operator()(const int& x) const {
        return a * x + b;
    }
    bool operator<(const line& rhs) const {
        if (type == 0) return a < rhs.a;
        else return r < rhs.l;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int p = 0ll, ans = 0ll;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        p += a[i] * i;
    }
    set<line> st; st.insert((line){ 1, 0, -inf, inf });
    for (int i = 2; i <= n; ++i) {
        type = 1;
        auto it = st.lower_bound((line){ -inf, -inf, a[i], a[i] });
        ans = max(ans, s[i - 1] - a[i] * i + (*it)(a[i]));
        line nl = (line){ i, -s[i - 1], -inf, inf };
        type = 0;
        it = st.lower_bound(nl);
        bool ins = true;
        while (it != st.end()) {
            if ((*it)(it->l) > nl(it->l) && (*it)(it->r) > nl(it->r)) {
                ins = false;
                break;
            }
            if ((*it)(it->l) <= nl(it->l) && (*it)(it->r) <= nl(it->r)) it = st.erase(it);
            else break;
        }
        if (!ins) continue;
        while (it != st.begin()) {
            --it;
            if ((*it)(it->l) <= nl(it->l) && (*it)(it->r) <= nl(it->r)) it = st.erase(it);
            else { ++it; break; }
        }
        if (it != st.begin()) {
            --it;
            line tmp = *it; it = st.erase(it);
            int t = nl.intersect(tmp);
            tmp.r = t; nl.l = t + 1;
            st.insert(tmp);
        }
        if (it != st.end()) {
            line tmp = *it; it = st.erase(it);
            int t = nl.intersect(tmp);
            tmp.l = t + 1; nl.r = t;
            st.insert(tmp);
        }
        st.insert(nl);
    }
    st.clear(); st.insert((line){ -n, -s[n], -inf, inf });
    for (int i = n - 1; i >= 1; --i) {
        type = 1;
        auto it = st.lower_bound((line){ -inf, -inf, -a[i], -a[i] });
        ans = max(ans, s[i] - a[i] * i + (*it)(-a[i]));
        line nl = (line){ -i, -s[i], -inf, inf };
        type = 0;
        it = st.lower_bound(nl);
        bool ins = true;
        while (it != st.end()) {
            if ((*it)(it->l) > nl(it->l) && (*it)(it->r) > nl(it->r)) {
                ins = false;
                break;
            }
            if ((*it)(it->l) <= nl(it->l) && (*it)(it->r) <= nl(it->r)) it = st.erase(it);
            else break;
        }
        if (!ins) continue;
        while (it != st.begin()) {
            --it;
            if ((*it)(it->l) <= nl(it->l) && (*it)(it->r) <= nl(it->r)) it = st.erase(it);
            else { ++it; break; }
        }
        if (it != st.begin()) {
            --it;
            line tmp = *it; it = st.erase(it);
            int t = nl.intersect(tmp);
            tmp.r = t; nl.l = t + 1;
            st.insert(tmp);
        }
        if (it != st.end()) {
            line tmp = *it; it = st.erase(it);
            int t = nl.intersect(tmp);
            tmp.l = t + 1; nl.r = t;
            st.insert(tmp);
        }
        st.insert(nl);
    }
    cout << p + ans << endl;
    return 0;
}
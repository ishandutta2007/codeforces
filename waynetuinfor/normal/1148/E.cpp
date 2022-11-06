#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int s[maxn], t[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
    if (accumulate(s, s + n, 0ll) != accumulate(t, t + n, 0ll)) {
        puts("NO");
        return 0;
    }

    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
        return s[i] < s[j];
    });
    sort(t, t + n);

    vector<tuple<int, int, int>> ans;
    vector<int> sup;
    for (int i = 0; i < n; ++i) {
        if (s[v[i]] > t[i]) 
            sup.push_back(i);
    }
    reverse(sup.begin(), sup.end());

    for (int i = 0; i < n; ++i) {
        while (sup.size() && sup.back() <= i) {
            sup.pop_back();
        }
        int j = v[i];
        if (s[j] > t[i]) {
            puts("NO");
            return 0;
        }
        if (s[j] == t[i]) continue;
        while (s[j] < t[i]) {
            if (sup.empty()) {
                puts("NO");
                return 0;
            }
            int d = min(t[i] - s[j], s[v[sup.back()]] - t[sup.back()]);
            ans.emplace_back(j, v[sup.back()], d);
            s[j] += d;
            s[v[sup.back()]] -= d;
            if (s[v[sup.back()]] == t[sup.back()]) sup.pop_back();
        }
    }

    /* while (st.size()) {
        int j = st.begin()->second;
        int v = st.begin()->first;
        st.erase(st.begin());
        if (i == n - 1) {
            assert(st.empty());
            assert(v == t[i]);
            break;
        }
        if (v > t[i]) {
            puts("NO");
            return 0;
        }
        if (v == t[i]) {
            ++i;
            continue;
        }

        int d = t[i] - v;
        int y = t[i + 1] + d;

        auto it = st.lower_bound(make_pair(y, -1));
        if (it != st.end()) {
            int k = it->second;
            int vk = it->first;
            st.erase(it);
            ans.emplace_back(j, k, d);
            st.insert(make_pair(vk - d, k));
            i++;
        } else {
            it = prev(st.end());
            int k = it->second;
            int vk = it->first;
            d = vk - t[i + 1];
            st.erase(it);
            if (d <= 0) {
                puts("NO");
                return 0;
            }
            ans.emplace_back(j, k, d);
            st.insert(make_pair(v + d, j));
            st.insert(make_pair(vk - d, k));     
        }
    } */

    puts("YES");
    assert((int)ans.size() <= 5 * n);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        int x, y, z; tie(x, y, z) = ans[i];
        printf("%d %d %d\n", x + 1, y + 1, z);
    }
}
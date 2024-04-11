#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

struct event {
    event(int t_, int s_, int e_, int ib_) : t(t_), s(s_), e(e_), ib(ib_) {}
    int t, s, e, ib;
    bool operator<(const event& a) {
        if (t == a.t) return ib < a.ib;
        return t < a.t;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> sa(n), ea(n), sb(n), eb(n);
    rep(i, 0, n) cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];

    rep(qq, 0, 2) {
        multiset<int> s, e;
        vector<event> events;
        rep(i, 0, n) {
            events.emplace_back(sa[i], sb[i], eb[i], 1);
            events.emplace_back(ea[i] + 1, sb[i], eb[i], 0);
        }
        sort(events.begin(), events.end());
        rep(i, 0, 2 * n) {
            if (events[i].ib) {
                if (!s.empty()) {
                    int smax = *s.rbegin();
                    int emin = *e.begin();
                    if (smax > events[i].e || events[i].s > emin) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                s.insert(events[i].s);
                e.insert(events[i].e);

            } else {
                s.erase(s.find(events[i].s));
                e.erase(e.find(events[i].e));
            }
        }
        swap(sa, sb);
        swap(ea, eb);
    }
    cout << "YES" << endl;
    return 0;
}
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int N;
    cin >> N;

    map<int, vector<pair<ll, ll>>> level;
    for (int i = 0; i < N; ++i) {
        ll x, y;
        cin >> x >> y;
        level[max(x, y)].push_back(make_pair(x, y));
    }

    for (auto& p : level) {
        int l = p.first;
        pair<ll, ll> left = make_pair(l, 0), right = make_pair(0, l);

        for (auto c : p.second) {
            if (c.first < left.first || c.second > left.second) left = c;
            if (c.first > right.first || c.second < right.second) right = c;
        }

        p.second = {left, right};
        if (left == right) p.second.pop_back();
    }

    ll lcost = 0, rcost = 0;
    pair<ll, ll> prel = make_pair(0, 0), prer = make_pair(0, 0);

    for (auto p : level) {
        ll d = dist(prel, prer);
        if (p.second.size() == 1) {
            ll ld = dist(prel, p.second[0]);
            ll rd = dist(prer, p.second[0]);
            lcost = rcost = min(rcost + d + ld, lcost + d + rd);
            prel = prer = p.second[0];
        } else {
            ll ld = min(lcost + d + dist(prer, p.second[0]),
                        rcost + d + dist(prel, p.second[0]));
            ll rd = min(lcost + d + dist(prer, p.second[1]),
                        rcost + d + dist(prel, p.second[1]));
            lcost = ld, rcost = rd;
            prel = p.second[0], prer = p.second[1];
        }
    }

    cout << min(lcost, rcost) + dist(prel, prer) << endl;
    return 0;
}
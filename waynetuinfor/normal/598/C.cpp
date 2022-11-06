#include <bits/stdc++.h>
#define double long double
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
pair<double, double> p[maxn];
const double pi = acos(-1);

double cal(double d) {
    d = fabs(d);
    if (d > pi) d = 2 * pi - d;
    return d;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    set<pair<double, int>> s;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        s.insert(make_pair(atan2(p[i].second, p[i].first), i));
    }
    pair<int, int> ans;
    double d = inf;
    for (int i = 0; i < n; ++i) {
        double deg = atan2(p[i].second, p[i].first);
        s.erase(make_pair(deg, i));
        auto it = s.lower_bound(make_pair(deg, -1));
        if (it != s.end() && cal(it->first - deg) < d) {
            d = cal(it->first - deg);
            ans = make_pair(i, it->second);
        }
        bool olala = false;
        if (it == s.begin()) olala = true;
        if (!olala) --it;
        if (!olala) if (cal(it->first - deg) < d) {
            d= cal(it->first - deg);
            ans = make_pair(i, it->second);
        }
        if (cal(s.begin()->first - deg) < d) {
            d = cal(s.begin()->first - deg);
            ans = make_pair(i, s.begin()->second);
        }
        if (cal(s.rbegin()->first - deg) < d) {
            d = cal(s.rbegin()->first - deg);
            ans = make_pair(i, s.rbegin()->second);
        }
        it = s.lower_bound(make_pair(0.0, -1));
        if (it != s.end() && cal(it->first - deg) < d) {
            d = cal(it->first - deg);
            ans = make_pair(i, it->second);
        }
        bool bang = false;
        if (it == s.begin()) bang = true;
        if (!bang) --it;
        if (!bang) if (cal(it->first - deg) < d) {
            d = cal(it->first - deg);
            ans = make_pair(i, it->second);
        }
        s.insert(make_pair(deg, i));
    }
    cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
    return 0;
}
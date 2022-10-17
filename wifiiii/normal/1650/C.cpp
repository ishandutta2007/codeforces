#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> a(m);
        for(auto &[x, y] : a) cin >> x >> y;
        auto b = a;
        sort(b.begin(), b.end(), [&](auto &i, auto &j) {return i.second < j.second;});
        map<pair<int,int>, int> mp;
        for(int i = 0; i < 2 * n; ++i) mp[b[i]] = 1;
        vector<int> ord(m);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j];});
        vector<int> c;
        ll s = 0;
        for(int i = 0; i < m; ++i) {
            if(mp.count(a[ord[i]])) {
                c.push_back(i);
                s += a[ord[i]].second;
            }
        }
        cout << s << '\n';
        for(int i = 0, j = c.size() - 1; i < j; ++i, --j) {
            cout << ord[c[i]] + 1 << ' ' << ord[c[j]] + 1 << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], cnt[maxn], b[maxn];

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == 0 && b.second) return false;
        if (b.second == 0 && a.second) return true;
        if (a.second == 0 && b.second == 0) return a.first < b.first;
        if (a.second > 1 && b.second == 1) return false;
        if (b.second > 1 && a.second == 1) return true;
        if (a.second > 1 && b.second > 1) return a.first < b.first;
        return a.first > b.first;
    }
};

int main() {
     ios_base::sync_with_stdio(false); cin.tie(0);
     int n, k; cin >> n >> k;
     set<pair<int, int>, cmp> s;
     vector<int> vec;
     for (int i = 1; i <= n; ++i) cin >> a[i], vec.push_back(a[i]);
     sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
     for (int i = 1; i <= n; ++i) b[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
     for (int i = 1; i <= k - 1; ++i) {
         ++cnt[b[i]];
         if (cnt[b[i]] > 1) s.erase(s.find(make_pair(a[i], cnt[b[i]] - 1)));
         s.insert(make_pair(a[i], cnt[b[i]]));
     }
     for (int i = k; i <= n; ++i) {
         ++cnt[b[i]];
         if (cnt[b[i]] > 1) s.erase(s.find(make_pair(a[i], cnt[b[i]] - 1)));
         s.insert(make_pair(a[i], cnt[b[i]]));
         if (s.begin()->second > 1) cout << "Nothing" << endl;
         else cout << s.begin()->first << endl;
         --cnt[b[i - k + 1]];
         s.erase(s.find(make_pair(a[i - k + 1], cnt[b[i - k + 1]] + 1)));
         if (cnt[b[i - k + 1]]) s.insert(make_pair(a[i - k + 1], cnt[b[i - k + 1]]));
         // cout << "cnt[a[i - 1]] = " << cnt[a[i - 1]] << endl;
     }
     return 0;
}
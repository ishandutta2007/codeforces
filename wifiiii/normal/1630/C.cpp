#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vector<int> l(n, -1), r(n, -1);
    for(int i = 0; i < n; ++i) {
        if(l[a[i]] == -1) l[a[i]] = r[a[i]] = i;
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    vector<pair<int,int>> seg;
    for(int i = 0; i < n; ++i) {
        if(l[i] == r[i] || l[i] + 1 == r[i]) continue;
        seg.push_back({l[i], r[i]});
    }
    seg.push_back({n, n});
    sort(seg.begin(), seg.end());
    int ans = 0, cnt = 0, left = -1, pre = -1, nxt = -1;
    for(auto [l, r] : seg) {
        if(l > pre) {
            if(nxt != pre) cnt += 1;
            pre = nxt;
            if(l > nxt) {
                if(left != -1) {
                    ans += pre - left - 1;
                }
                left = l;
                pre = r;
                nxt = r;
            }
        }
        nxt = max(nxt, r);
    }
    ans -= cnt;
    cout << ans << '\n';
}
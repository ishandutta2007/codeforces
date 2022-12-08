#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+5;
int a[maxn], b[maxn], pos[maxn*2], vis[maxn*2];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        pos[a[i]] = pos[b[i]] = i;
    }
    int l = 1, r = 2 * n;
    while(l < r) {
        if(pos[l] == pos[r]) {
            ++l, --r;
        } else {
            break;
        }
    }
    vector<pair<int,int>> be, ed;

    int mn = l, mx = r;
//    cout << l << " " << r << " " << cl << " " << cr << endl;
    int anss = 0;
    for(int i = r; i >= l; --i) {
        if(vis[i]) continue;
        int cnt = 0;
        int N = 1;
        int p = pos[i];
        if(b[p] == i) {
            swap(a[p], b[p]);
            if(abs(a[p] - b[p]) != 1)  ++cnt;
        }
        if(abs(a[p] - b[p]) == 1) --N;
        assert(a[p] == i);
        ed.push_back({a[p], b[p]});
        vis[a[p]] = vis[b[p]] = 1;
//        if(mn == b[p]) --N;
        int mx2=a[p],mn2=b[p];
        while(vis[mn]) ++mn;
        while(vis[mx]) --mx;
        while(mn < mn2 || mx > mx2) {
//            cout << mn << " " << mx << endl;
            assert(mn <= mx);
            if(mn < mn2) {
                int p2 = pos[mn];
                ++N;
                if(b[p2] == mn) {
                    swap(a[p2], b[p2]);
                    if(abs(a[p2] - b[p2]) != 1) ++cnt;
                }
                if(abs(a[p2] - b[p2]) == 1) --N;
                assert(a[p2] == mn);
                be.push_back({a[p2], b[p2]});
                mx2 = min(mx2, b[p2]);
                vis[a[p2]] = vis[b[p2]] = 1;
                while(vis[mn]) ++mn;
                while(vis[mx]) --mx;
            } else {
                int p2 = pos[mx];
                ++N;
                if(b[p2] == mx) {
                    swap(a[p2], b[p2]);
                    if(abs(a[p2] - b[p2]) != 1) ++cnt;
                }
                if(abs(a[p2] - b[p2]) == 1) --N;
                assert(a[p2] == mx);
                ed.push_back({a[p2], b[p2]});
                mn2 = max(mn2, b[p2]);
                vis[a[p2]] = vis[b[p2]] = 1;
                while(vis[mx]) --mx;
                while(vis[mn]) ++mn;
            }
        }
//        cout << cnt << " " << N << " " << mn << " " << mx << endl;
        anss += min(N - cnt, cnt);
    }
    reverse(ed.begin(), ed.end());
    vector<pair<int,int>> ans;
    for(auto p : be) ans.push_back(p);
    for(auto p : ed) ans.push_back(p);
    int ok = 1;
//    for(auto p:ans) cerr<<p.first<<" "<<p.second<<endl;
    for(int i = 1; i < ans.size(); ++i) {
        if(ans[i].first < ans[i-1].first || ans[i].second > ans[i-1].second) ok = 0;
    }
//    cout << cnt << " " << ans.size() << endl;
    if(ok) cout << anss << '\n';
    else cout << -1 << endl;
}
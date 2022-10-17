#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> a[200005];
vector<pair<int,int>> g[5000005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
    sort(a + 1, a + 1 + n);
    if(n <= 5000) {
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                g[a[i].first + a[j].first].push_back({i, j});
            }
        }
        for(int i = 1; i <= 5000000; ++i) {
            if(g[i].size() > 1) {
                set<int> s;
                for(auto p : g[i]) {
                    s.insert(p.first);
                    s.insert(p.second);
                    if(s.size() > 10) break;
                }
                vector<int> p;
                for(int j : s) p.push_back(j);
                sort(p.begin(), p.end());
                for(int i1 : p) {
                    for(int i2 : p) {
                        if(i1 == i2) continue;
                        for(int i3 : p) {
                            if(i2 == i3 || i1 == i3) continue;
                            for(int i4 : p) {
                                if(i1 == i4 || i2 == i4 || i3 == i4) continue;
                                if(a[i1].first + a[i2].first == a[i3].first + a[i4].first) {
                                    cout << "YES" << endl;
                                    cout << a[i1].second << " " << a[i2].second << " " << a[i3].second << " " << a[i4].second << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        map<int,int> vis;
        for(int i = 1; i <= n; i += 2) {
            if(vis.count(a[i+1].first - a[i].first)) {
                cout << "YES" << endl;
                int pos = vis[a[i+1].first - a[i].first];
                cout << a[pos].second << " " << a[i+1].second << " " << a[pos+1].second << " " << a[i].second << endl;
                return 0;
            }
            vis[a[i+1].first - a[i].first] = i;
        }
    }
    cout << "NO" << endl;
}
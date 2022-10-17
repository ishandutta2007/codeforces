#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    vector<vector<int>> pos(N);
    vector<int> vis;
    for(auto &[x, y] : a) cin >> x >> y, pos[x].push_back(y), vis.push_back(x);
    sort(vis.begin(), vis.end());
    vis.resize(unique(vis.begin(), vis.end()) - vis.begin());
    double mx = -1; int ans = -1; vector<int> choice;
    for(int i = 1; i <= 200 && i <= vis.size(); ++i) {
        vector<int> b;
        for(int j : vis) {
            int tmp = 0;
            for(int k : pos[j]) {
                if(i <= k) tmp += i;
                else tmp += k;
            }
            b.push_back(tmp);
        }
        vector<int> ord(b.size());
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return b[i] > b[j];});
        ll tot = 0;
        for(int j = 0; j < i; ++j) tot += b[ord[j]];
        double exp = 1.0 * tot / i;
        if(exp > mx) {
            mx = exp;
            ans = i;
            choice.clear();
            for(int j = 0; j < i; ++j) {
                choice.push_back(vis[ord[j]]);
            }
        }
    }
    cout << ans << '\n';
    for(int i : choice) cout << i << " "; cout << '\n';
}
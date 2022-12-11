#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

#define X first
#define Y second
const int N = 5e5 + 10;

int n;
ll sum;
ii a[N];
vector<int> v[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for(int i = 0; i <= n; i++) v[i].clear();
        for(int i = 1; i <= n; i++) {
            int mi, pi;
            cin >> mi >> pi;
            v[mi].push_back(pi);
        }
        vector<int> imp;
        for(int i = 0; i <= n; i++) if (!v[i].empty()) {
            imp.push_back(i);
        }
        ll ans = 0;
        ll use = 0;
        ll rem = n;

        priority_queue<ll> pq;
        for(int i = imp.size() - 1; i >= 0; i--) {
            rem -= v[imp[i]].size();
            for(auto j : v[imp[i]]) pq.push(-j);

            int need = imp[i] - (rem + use);
            while (need > 0) {
                use++, ans += -pq.top();
                pq.pop();
                need--;
            }
        }
        cout << ans << '\n';
    }
}
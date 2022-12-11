#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e3 + 10;

int n;
ll a[N][2];
pair<ll, int> per[N];

vector<int> gr[N];
int tr[N];

bool merge(int x, int y) {
    x = tr[x], y = tr[y];
    if (x == y) return 0;
    for(auto u : gr[y]) {
        gr[x].push_back(u);
        tr[u] = x;
    }
    return 1;
}
map<ll, vector<pair<int, int>>> ma;

void solve() {
    for( ; ; ) {
        vector<int> v[2];
        for(int i = 1; i <= n; i++) {
            //cout << a[i][0] << " " << a[i][1] << endl;
            v[(a[i][0] + a[i][1]) % 2].push_back(i);
        }
        if (!v[0].empty() && !v[1].empty()) {
            cout << v[0].size() << '\n';
            for(auto i : v[0]) cout << i << " "; 
            return;
        }

        for(int i = 0; i <= 1; i++) v[i].clear();
        
        for(int i = 1; i <= n; i++) {
            v[a[i][0] % 2].push_back(i);
        }
        if (!v[0].empty() && !v[1].empty()) {
            cout << v[0].size() << '\n';
            for(auto i : v[0]) cout << i << " "; 
            return;
        }

        for(int i = 1; i <= n; i++) {
            a[i][0] /= 2;
            a[i][1] /= 2;
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        for(int j = 0; j <= 1; j++) 
            a[i][j] = a[i][j] + 1e6 + 10;
    }
    solve();
}
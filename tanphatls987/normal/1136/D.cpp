#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 3e5 + 10;
int n;
int p[N];
set<ii> eSet;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        eSet.insert(ii(x, y));
    }
    vector<int> guard;
    guard.push_back(p[n]);
    int ans = 0;
    for(int i = n - 1; i >= 1; i--) {
        for(int j = guard.size() - 1; j >= 0; j--) {
            if (!eSet.count(ii(p[i], guard[j]))) {
                guard.push_back(p[i]);
                break;
            }
            if (j == 0) ans++;
        }
    }
    cout << ans;
}
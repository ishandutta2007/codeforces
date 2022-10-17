#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

int a[MN], dist[MN];

void solve(){
    int N, D; cin >> N >> D;
    for (int i = 0; i < N; ++i){
        dist[i] = -1;
        cin >> a[i];
    }
    queue<int> q;
    for (int i = 0; i < N; ++i){
        if (a[i] == 0) dist[i] = 0;
        if (a[i] == 0 && a[(i + D) % N] == 1){
            q.push((i + D) % N);
            dist[(i + D) % N] = 1;
        }
    }
    while (!q.empty()){
        int v = q.front(); q.pop();
        a[v] = 0;
        if (a[(v + D) % N] == 1){
            q.push((v + D) % N);
            dist[(v + D) % N] = dist[v] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i){
        if (dist[i] == -1){
            cout << -1 << '\n';
            return;
        }
        ans = max(ans, dist[i]);
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        solve();
    }
}
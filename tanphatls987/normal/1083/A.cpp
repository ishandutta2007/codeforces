#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 3e5 + 10;
int n;
int w[N];
vector<ii> v[N];
ii pa[N];
long long f[N][2];
int q[N];
void BFS() {
    int top = 1, bot = 1;
    q[1] = 1;
    while (top <= bot) {
        int x = q[top++];
        for(auto i : v[x]) if (i.X != pa[x].X) {
            pa[i.X] = ii(x, i.Y);
            q[++bot] = i.X;
        }
    }
}
long long solve() {
    long long ans = 0;
    for(int turn = n; turn >= 1; turn--) {
        int x = q[turn];
        f[x][0] = f[x][1] = w[x];
        for(auto i : v[x]) if (i.X != pa[x].X) {
            ans = max(ans, f[x][1] + f[i.X][1] - i.Y);
            //f[x][1] = max(f[x][0] + f[i.X][1] - i.Y, f[x][1] + max(0LL, f[i.X][0] - 2 * i.Y)); 
            //f[x][0] += max(0LL, f[i.X][0] - 2 * i.Y);
            f[x][1] = max(f[x][1], f[i.X][1] - i.Y + w[x]);
        }
        ans = max(ans, f[x][1]);
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i < n; i++) {
        int x, y, wei;
        cin >> x >> y >> wei;
        v[x].push_back(ii(y, wei));
        v[y].push_back(ii(x, wei));
    }
    BFS();
    cout << solve();
}
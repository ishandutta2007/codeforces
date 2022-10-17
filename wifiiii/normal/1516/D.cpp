#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
int rpos[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> lst(n + 1), a(n + 1);
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        int l = lst[i-1];
        for(int j = 1; j * j <= x; ++j) {
            if(x % j == 0) {
                if(j != 1) {
                    l = max(l, rpos[j]);
                    rpos[j] = i;
                }
                if(x / j != j) {
                    l = max(l, rpos[x / j]);
                    rpos[x / j] = i;
                }
            }
        }
        lst[i] = l;
    }
    vector<vector<int>> go(20, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i) go[0][i] = lst[i];
    for(int j = 1; j < 20; ++j) {
        for(int i = 1; i <= n; ++i) {
            go[j][i] = go[j-1][go[j-1][i]];
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i = 19; i >= 0; --i) {
            if(go[i][r] >= l) {
                ans += 1 << i;
                r = go[i][r];
            }
        }
        cout << ans + 1 << '\n';
    }
}
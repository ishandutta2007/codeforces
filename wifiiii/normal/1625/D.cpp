#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 5;
int tr[N*30][2], idx[N*30];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if(k == 0) {
        cout << n << '\n';
        for(int i = 1; i <= n; ++i) cout << i << " ";
        cout << '\n';
        return 0;
    }
    int high = 32 - __builtin_clz(k);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; ++i) {
        mp[a[i] & ~((1 << high) - 1)].push_back(i);
    }
    vector<int> ans;
    for(auto [_, b] : mp) {
        int tot = 0, found = 0;
        for(int j : b) {
            int p = 0, x = a[j];
            for(int i = 29; i >= 0; --i) {
                if(!tr[p][x >> i & 1]) tr[p][x >> i & 1] = ++tot;
                p = tr[p][x >> i & 1];
            }
            idx[p] = j;
            int mx = 0;
            p = 0;
            for(int i = 29; i >= 0; --i) {
                if(tr[p][(x >> i & 1) ^ 1]) p = tr[p][(x >> i & 1) ^ 1], mx |= 1 << i;
                else p = tr[p][x >> i & 1];
            }
            if(mx >= k) {
                ans.push_back(j);
                ans.push_back(idx[p]);
                found = 1;
                break;
            }
        }
        if(!found) {
            ans.push_back(b[0]);
        }
        for(int i = 0; i <= tot; ++i) tr[i][0] = tr[i][1] = idx[i] = 0;
    }
    if(ans.size() < 2) {
        cout << -1 << '\n';
    } else {
        cout << ans.size() << '\n';
        for(int i : ans) cout << i + 1 << ' ';
        cout << '\n';
    }
}
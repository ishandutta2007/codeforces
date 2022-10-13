#include <bits/stdc++.h>
using namespace std;

int dp[505][505], t[505][505];

int query(vector<int> &nums) {
    cout << "? ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] + 1 << " ";
    }
    cout << "\n";
    cout.flush();
    int x; cin >> x;

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    if((k % 2 == 0 && n % 2 == 1)) {
        cout << -1 << "\n";
        return 0;
    }
    int ans = 0;
    if(n % k == 0) {
        for(int i = 0; i < n / k; i++) {
            vector<int> v;
            for(int j = i * k; j < k * (i + 1); j++)
                v.push_back(j);
            ans ^= query(v);
        }
    }
    else {
        int num = 1000000000, go = 0;
        for(int i = 1; i <= 500; i++) {
            int x = i * k;
            if(x < n && (n - x) % 2 == 0 && (n - x) < 2 * k) {
                int tmp = i + 2;
                if(tmp < num)
                    num = tmp, go = i;
            }
        }
        if(num == 1000000000) {
            int l = n - k;
            for(int i = 0; i < n / 2; i += l) {
                vector<int> x, y;
                int st = i, en = min(i + l, n / 2);
                if(st >= en) break;
                for(int j = st; j < en; j++) {
                    x.push_back(j);
                    y.push_back(n - j - 1);
                }
                for(int j = 0; j < n; j++) {
                    if((j >= st && j < en) || (j >= n - en && j <= n - st - 1)) continue;
                    if(x.size() < k && y.size() < k)
                        x.push_back(j), y.push_back(j);
                    
                }
                ans ^= query(x), ans ^= query(y);
            }
            cout << "! " << ans << "\n";
            cout.flush();
            return 0;
        }
        for(int i = 0; i < go; i++) {
            vector<int> v;
            for(int j = i * k; j < k * (i + 1); j++)
                v.push_back(j);
            ans ^= query(v);
        }
        int left = n - go * k;
        vector<int> x, y;
        for(int i = 0; i < k - left / 2; i++) {
            x.push_back(i), y.push_back(i);
        }
        for(int i = go * k; i < go * k + left / 2; i++) {
            x.push_back(i);
        }
        for(int i = go * k + left / 2; i < go * k + left; i++) {
            y.push_back(i);
        }
        ans ^= query(x);
        ans ^= query(y);
    }
    cout << "! " << ans << "\n";
}